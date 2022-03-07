#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, long long left, long long right) {
    int* answer = (int*)malloc(sizeof(int) * (right - left + 1)); //길이
    int idx = 0;
    
    //규칙을 보면 
    for (long long i = left; i <= right; ++i) {
        int row = i / n;
        int col = i % n;
        
        //행과 열 값 중 더 큰 값 + 1로 해야함
        int ele = row > col ? row + 1 : col + 1;
        //정답 삽입
        answer[idx++] = ele;
    }
    //반환
    return answer;
}
