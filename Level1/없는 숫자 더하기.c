#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_arr(int numbers[], size_t numbers_len, int n) {
    for (int i = 0; i < numbers_len; ++i) {
        if (numbers[i] == n)
            return true;
    }
    return false;
}

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int answer = 0;
    
    for (int i = 0; i <= 9; ++i) {
        if (!is_arr(numbers, numbers_len, i))
            answer += i;
    }
    return answer;
}