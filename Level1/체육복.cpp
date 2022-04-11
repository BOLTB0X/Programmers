#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> cnt(n+1, 1); // 여분
    
    // 분실
    for (int& l : lost) 
        cnt[l]--;
    
    // 여분
    for (int& r: reserve)
        cnt[r]++;
    
    // 그리디
    for (int i = 1; i <=n; ++i) {
        // 해당 학생은 참가 가능
        if (cnt[i] != 0)
            answer++;
        
        // 빌려야하는 학생이면
        else if (cnt[i] == 0){
            // 그 학생이 1번이면
            if (i == 1) {
              if (cnt[i + 1] > 1) {
                  answer++;
                  cnt[i + 1]--;
              }
            }
            // 그 학생이 맨 뒤이면
            else if (i == n) {
                if (cnt[i - 1] > 1) {
                  answer++;
                  cnt[i - 1]--;
              }
            }
            
            // 나머지
            else {
                // 왼쪽 학생 체크
                if (cnt[i - 1] > 1) {
                  answer++;
                  cnt[i - 1]--;
              }
                // 오른쪽 학생 체크
                else if (cnt[i+1] > 1){
                    answer++;
                    cnt[i + 1]--;
                }
            }
        }
    }
    return answer;
}
