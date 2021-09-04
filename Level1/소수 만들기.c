#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_primenumber(int n) {
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i < n / 2; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    for (int i = 0; i < nums_len; i++) {
        for (int j = i + 1; j < nums_len; j++) {
            for (int k = j + 1; k < nums_len; k++) {
                int tmp_n = nums[i] + nums[j] + nums[k];
                if (is_primenumber(tmp_n))
                    answer++;
            }
        }
    }
    return answer;
}