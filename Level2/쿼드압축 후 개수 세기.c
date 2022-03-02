#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int z_cnt = 0, o_cnt = 0;

//재귀를 통한 분할 정복으로 압축
void compasstion(int** arr, int y, int x, int size, int cmp) {
    int half = size / 2;
    int flag = 1; //체크용
    
    //탈출 조건
    if (size < 2) {
        if (cmp == 1)
            o_cnt++;
        else
            z_cnt++;
        return;
    }
    
    //분할 가능한지 탐색
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
    
    //분할 가능하다면
    if (flag == 1) {
        if (cmp == 1)
            o_cnt++;
        else
            z_cnt++;
        return;
    }
    
    //분할 시작
    //1 범위를 반으로
    compasstion(arr, y, x, half, arr[y][x]);
    //2 x축만
    compasstion(arr, y, x + half, half, arr[y][x + half]);
    //3 y축만
    compasstion(arr, y + half, x, half, arr[y + half][x]);
    //4 다
    compasstion(arr, y + half, x + half, half, arr[y + half][x + half]);
    
    return;
}

int* solution(int** arr, size_t arr_rows, size_t arr_cols) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0, answer[1] = 0;
    
    //분할정복으로 압축 시작
    compasstion(arr, 0, 0, arr_rows, arr[0][0]);
    answer[0] = z_cnt;
    answer[1] = o_cnt;
    return answer;
}
