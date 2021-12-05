#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//최대공약수
int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

long long solution(int w, int h) {
    long long answer = (long long)w * (long long)h - (w + h);
    answer += gcd(w, h);

    return answer;
}