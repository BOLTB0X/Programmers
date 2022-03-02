#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MS 100000001

char str[MS] = { '\0', }; // 문자열
int idx = 0;

//3진법 변환
void get_ter(int n) {
    while (n > 0) {
        int mod = n % 3;
        str[idx++] = (char)(mod + '0');
        n /= 3;
    }

    return;
}

//10진수 변환
int get_dec(void) {
    int tot = 0;
    //idx가 곧 문자열의 길이
    for (int i = idx - 1, j = 1; i >= 0; --i, j *= 3)
        tot += j * (int)(str[i] - '0');

    return tot;
}

int solution(int n) {
    int answer = 0;

    get_ter(n);
    answer = get_dec();
    return answer;
}