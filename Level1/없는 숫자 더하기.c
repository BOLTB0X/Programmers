#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//배열안에 있는 지 체크
int is_arr(int numbers[], size_t numbers_len, int n) {
    for (int i = 0; i < numbers_len; ++i) {
        if (numbers[i] == n)
            return 1;
    }
    return 0;
}

int solution(int numbers[], size_t numbers_len) {
    int answer = 0;
    
    for (int i = 0; i <= 9; ++i) {
        //배열안에 원소가 있는 가?
        if (is_arr(numbers, numbers_len, i) == 0)
            answer += i;
    }
    return answer;
}
