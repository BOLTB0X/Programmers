#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i; j < n; j++) {
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;

    sort(A, A_len);
    sort(B, B_len);

    for (int i = 0; i < A_len; i++) {
        answer += (A[i] * B[B_len-1-i]);
    }
    return answer;
}