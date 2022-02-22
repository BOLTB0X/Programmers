#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MV 1000001

int solution(int n) {
    int answer = 0;
    for (int i = 2; i <= MV; ++i) {
        if (n % i == 1) {
            answer = i;
            break;
        }
    }
    return answer;
}