#include <string>
#include <vector>

using namespace std;

//3진법 변환
string trans_num(int n) {
    string str = "";
    while (n >= 1) {
        int r = (n % 3);
        str += (char)(r + '0');
        n /= 3;
    }
    return str;
}

//십진법 반환
int get_number(string s) {
    int result = 0;
    int mul = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        result += (s[i] - '0') * mul;
        mul *= 3;
    }
    return result;
}

int solution(int n) {
    int answer = 0;
    answer = get_number(trans_num(n));
    return answer;
}
