#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, long long left, long long right) {
    int* answer = (int*)malloc(sizeof(int) * (right - left + 1)); //����
    int idx = 0;

    //��Ģ�� ���� 
    for (long long i = left; i <= right; ++i) {
        int row = i / n;
        int col = i % n;

        //��� �� �� �� �� ū �� + 1�� �ؾ���
        int ele = row > col ? row + 1 : col + 1;
        //���� ����
        answer[idx++] = ele;
    }
    return answer;
}