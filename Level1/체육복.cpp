#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> check(n+1,1);
    check[0] = 0;
    
    for (int i=0; i<lost.size(); ++i)
        check[lost[i]]--;
    
    for (int i=0; i < reserve.size(); ++i)
        check[reserve[i]]++;
   
    for (int i=1; i <= n; ++i) {
        if (check[i] == 0) {
            if (i != 1 && check[i-1] > 1) {
                check[i]++;
                check[i-1]--;
            }
            else if (i!=n && check[i+1] > 1) {
                check[i]++;
                check[i+1]--;
            }
        }
    }
    
    for (int i=1;i<=n; ++i) {
        if(check[i] >= 1)
            answer++;
    }
    return answer;
}
