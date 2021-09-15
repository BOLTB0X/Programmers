#include <string>
#include <vector>

using namespace std;

int pow(int a, int b) {
    int result = 1;
    if (b == 0)
        return 1;
    for (int i = 1; i <= b; i++) {
        result *= a;
    }
    return result;
}

int solution(int n) {
    int answer = 0;
    string tmp_n;

    while (n>=1) {
        tmp_n += (char)(n % 3) + '0';
        n /= 3;
    }
    int idx = 1;
    for (int i = tmp_n.length()-1; i >=0 ; i--) {
        answer += (tmp_n[i]-'0')*idx;
        idx *= 3;
    }

    return answer;
}