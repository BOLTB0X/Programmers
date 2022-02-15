#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int MAX(int a, int b) {
    return a > b ? a : b;
}

int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int row_len = -1, col_len = -1;

    for (int i = 0; i < sizes_rows; ++i) {
        //세로가 클 경우
        if (sizes[i][0] < sizes[i][1]) {
            col_len = MAX(col_len, sizes[i][1]);
            row_len = MAX(row_len, sizes[i][0]);
        }
        //가로가 클 경우
        else {
            col_len = MAX(col_len, sizes[i][0]);
            row_len = MAX(row_len, sizes[i][1]);
        }
    }

    answer = col_len * row_len;
    return answer;
}