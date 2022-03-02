#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int tmp[10001];
int tmp_idx = 0;

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

//중복 체크
int is_duplicate_element(int ele) {
    for (int i = 0; i < tmp_idx; ++i) {
        if (tmp[i] == ele)
            return 1; //중복 O
    }
    return 0; //중복 X
}

int* solution(int numbers[], size_t numbers_len) {
    //완전탐색 이용
    for (int i = 0; i < numbers_len - 1; ++i) {
        for (int j = i + 1; j < numbers_len; ++j) {
            int ele = numbers[i] + numbers[j]; //원소 후보;
            
            //중복체크하며 삽입
            if (is_duplicate_element(ele) == 0)
                tmp[tmp_idx++] = ele;
        }
    }
    
    //정답 배열 동적 할당
    int* answer = (int*)malloc(sizeof(int) * tmp_idx);
    for (int i = 0; i < tmp_idx; ++i)
        answer[i] = tmp[i];
    
    //퀵정렬 이용
    qsort(answer, tmp_idx, sizeof(int), compare);
    return answer;
}
