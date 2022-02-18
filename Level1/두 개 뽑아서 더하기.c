#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int tmp[10000];

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* solution(int numbers[], size_t numbers_len) {
    int tmp_idx = 0, flag, ele;

    //완전탐색
    for (int i = 0; i < numbers_len - 1; ++i) {
        for (int j = i + 1; j < numbers_len; ++j) {
            ele = numbers[i] + numbers[j];
            flag = 1;

            //중복되는 검사
            for (int k = 0; k < tmp_idx; ++k) {
                if (ele == tmp[k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                tmp[tmp_idx++] = ele;
            }
        }
    }

    //정답 배열 생성
    int* answer = (int*)malloc(sizeof(int) * tmp_idx);
    for (int i = 0; i < tmp_idx; ++i)
        answer[i] = tmp[i];

    //정렬
    qsort(answer, tmp_idx, sizeof(int), compare);
    return answer;
}