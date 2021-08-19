#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    bool answer = false;
    int tmp = 0;
    int s_size = strlen(s);

    for (int i = 0; i < s_size; i++) {
        if (tmp < 0) {
            answer = false;
            break;
        }
        else {
            if (s[i] == '(') tmp += 1;
            else if (s[i] == ')') tmp -= 1;
        }
    }
    if (tmp == 0)
        answer = true;
    else
        answer = false;
    return answer;
}