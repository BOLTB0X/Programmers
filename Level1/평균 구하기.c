#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len�� �迭 arr�� �����Դϴ�.
double solution(int arr[], size_t arr_len) {
    double answer = 0;
    int tot = 0;
    for (int i = 0; i < arr_len; ++i)
        tot += arr[i];

    //�Ҽ����� �ʿ��ϹǷ�
    answer = (double)tot / arr_len;
    return answer;
}