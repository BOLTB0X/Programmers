#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//최소 공배수
int gcd(int a, int b) {
    if (a % b == 0) return b;
    else
        return gcd(b, a % b);
}

//최소 공배수
int lcm(int a, int b) {
    return a * b / gcd(a,b);
}

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    int answer = arr[0];
    
    for (int i = 1; i < arr_len; i++) {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}