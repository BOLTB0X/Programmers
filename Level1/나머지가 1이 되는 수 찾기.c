#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MV 1000001

int solution(int n) {
    int answer = 0;
    
    //완전탐색
    for (int i = 2; i < MV; ++i) {
        //찾았다면
        if (n % i == 1) {
            answer = i;
            break;
        }
    }
    //반환
    return answer;
}
