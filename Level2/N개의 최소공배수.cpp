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
    return (a*b / gcd(a,b));
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    //순차적으로 비교
    for (int i=1; i<arr.size(); ++i) 
        answer = lcm(answer,arr[i]);
    
    return answer;
}
