#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    //정답
    char* answer;
    //문자열길이함수 이용
    int len = strlen(s);

    //길이가 짝수인 경우
    if (len % 2 == 0) {
        answer = (char*)malloc(3);
        answer[0] = s[len / 2 - 1];
        answer[1] = s[len / 2];
        answer[2] = '\0';
    }

    //홀수
    else {
        answer = (char*)malloc(2);
        answer[0] = s[len / 2];
        answer[1] = '\0';
    }
    return answer;
}