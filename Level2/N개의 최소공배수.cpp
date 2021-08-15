#include <string>
#include <vector>
using namespace std;

//2���� �ִ� ����� �Լ�
int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

//2���� �ּ� ����� �Լ�
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for (int i=1;i<arr.size();i++) {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}