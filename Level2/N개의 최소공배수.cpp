#include <string>
#include <vector>

using namespace std;

//최대공약수
int gcd(int a, int b) {
    if (a%b == 0)
        return b;
    return gcd(b,a%b);
}

//최소공배수
int lcm(int a, int b) {
    return a*b/gcd(a,b);
}

int solution(vector<int> arr) {
    //배열의 첫 원소를 셋팅
    int answer = arr[0];
    
    //각 원소들을 순회하며 최소공배수를 구함
    for (int i=1;i<arr.size();++i) {
        answer = lcm(answer,arr[i]);
    }
    
    return answer;
}
