#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    long long answer = 0;
    for (long long i = 0; i < strlen(s); ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            answer = answer * 10 + (s[i] - '0');
        else {
            if (s[i] == 'o' && s[i + 1] == 'n' && s[i+2] == 'e')
                answer = answer * 10 + 1;
            else if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o')
                answer = answer * 10 + 2;
            else if (s[i] == 't' && s[i + 1] == 'h' && s[i + 2] == 'r')
                answer = answer * 10 + 3;
            else if (s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'u')
                answer = answer * 10 + 4;
            else if (s[i] == 'f' && s[i + 1] == 'i' && s[i + 2] == 'v')
                answer = answer * 10 + 5;
            else if (s[i] == 's' && s[i + 1] == 'i' && s[i + 2] == 'x')
                answer = answer * 10 + 6;
            else if (s[i] == 's' && s[i + 1] == 'e' && s[i + 2] == 'v')
                answer = answer * 10 + 7;
            else if (s[i] == 's' && s[i + 1] == 'e' && s[i + 2] == 'v')
                answer = answer * 10 + 7;
            else if (s[i] == 'e' && s[i + 1] == 'i' && s[i + 2] == 'g')
                answer = answer * 10 + 8;
            else if (s[i] == 'n' && s[i + 1] == 'i' && s[i + 2] == 'n')
                answer = answer * 10 + 9;
            else if (s[i] == 'z' && s[i + 1] == 'e' && s[i + 2] == 'r')
                answer = answer * 10;
        }
    }
    return answer;
}