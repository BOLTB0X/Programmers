#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string s_x = to_string(x);
    int tmp = 0;
    //자릿수의 합
    for (int i = 0; i < s_x.length(); i++) {
        tmp += (s_x[i] - '0');
    }
    if (x % tmp == 0) {
        return answer;
    }
    else
        answer = false;
    return answer;
}