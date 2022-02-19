#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int z_cnt = 0, o_cnt = 0;

void compassion(int** arr, int y, int x, int size, int cmp) {
    int half = size / 2, flag = 1;
    
    //재귀를 활용한 분할탐색의 탈출 조건
    if (size < 2) {
        if (cmp == 1)
            o_cnt++;
        else
            z_cnt++;
        return;
    }
    
    for (int i = y; i <  y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (cmp != arr[i][j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            break;
    }
    
    //분할이 정상적으로 진행된 것이므로 
    if (flag == 1) {
        if (cmp == 1)
            o_cnt++;
        else
            z_cnt++;
        return;
    }
    //분할탐색 시작
    compassion(arr, y, x, half, arr[y][x]); //범위 
    compassion(arr, y + half, x, half, arr[y+half][x]); //한칸
    compassion(arr, y, x + half, half, arr[y][x + half]); //한칸
    compassion(arr, y + half, x + half, half, arr[y + half][x + half]); //대각선
    return;
}

int* solution(int** arr, size_t arr_rows, size_t arr_cols) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0, answer[1] = 0;
    
    compassion(arr, 0, 0, arr_rows, arr[0][0]);
    answer[0] = z_cnt, answer[1] = o_cnt;
    return answer;
}
