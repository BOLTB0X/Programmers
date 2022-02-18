#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int z_cnt = 0, o_cnt = 0;

//분할 정복 이용
void Compassion(int** arr, int y, int x, int size, int cmp) {
    int half = size / 2, flag = 1;

    if (size < 2) {
        if (cmp == 1)
            o_cnt++;
        else
            z_cnt++;
        return;
    }

    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (arr[i][j] != cmp) {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            break;
    }

    //압축이 된 것이므로
    //압축 처리 후 종료;
    if (flag == 1) {
        if (cmp == 1)
            o_cnt++;
        else
            z_cnt++;
        return;
    }

    //분할 정복
    //범위을 반으로
    Compassion(arr, y, x, half, arr[y][x]);
    //전진
    Compassion(arr, y + half, x, half, arr[y + half][x]);
    Compassion(arr, y, x + half, half, arr[y][x + half]);
    //대각선
    Compassion(arr, y + half, x + half, half, arr[y + half][x + half]);
    return;
}

int* solution(int** arr, size_t arr_rows, size_t arr_cols) {
    int* answer = (int*)malloc(sizeof(int) * 2);

    Compassion(arr, 0, 0, arr_rows, arr[0][0]);
    answer[0] = z_cnt, answer[1] = o_cnt;
    return answer;
}