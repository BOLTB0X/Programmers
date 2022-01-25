#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* number, int k) {
    char* answer = (char*)malloc(sizeof(char) * strlen(number));
    memset(answer, 0, sizeof(char) * strlen(number));
    char max_num[1000001] = { 0, };
    int num_idx = 0;

    int size = strlen(number) - k;
    int max_idx = 0;
    int start = 0;

    for (long long i = 0; i < size; ++i) {
        max_idx = start;
        char max_tmp = number[max_idx];

        for (long long j = start + 1; j <= k + i; ++j) {
            if (max_tmp < number[j]) {
                max_tmp = number[j];
                max_idx = j;
            }
        }

        start = max_idx + 1;
        max_num[num_idx++] = max_tmp;
    }
    
    strcpy(answer, max_num);
    return answer;
}
