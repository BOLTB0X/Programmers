#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int board[1001][1001];

const int dy[3] = { 1, 0, -1 };
const int dx[3] = { 0, 1, -1 };

//초기화
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            board[i][j] = 0;
    }
    return;
}

//범위 체크
int in_Range(int y, int x, int n) {
    return 1 <= y && y <= n && 1 <= x && x <= n;
}

int* solution(int n) {
    int* answer = (int*)calloc(n * (n + 1) / 2, sizeof(int) * 1001);
    int idx = 0;
    int number = 1, cy = 1, cx = 1;

    //보드 초기화
    init(n);

    //달팽이 삼각형 형태로 값 할당
    while (in_Range(cy, cx, n) == 1 && board[cy][cx] == 0) {
        for (int dir = 0; dir < 3; ++dir) {
            //탈출 조건
            if (in_Range(cy, cx, n) == 0 || board[cy][cx] != 0)
                break;

            while (1) {
                board[cy][cx] = number++;
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];

                if (in_Range(ny, nx, n) == 0 || board[ny][nx] != 0) {
                    cy += dy[(1 + dir) % 3];
                    cx += dx[(1 + dir) % 3];
                    break;
                }

                cy = ny, cx = nx;
            }
        }
    }

    //삽입
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (board[i][j] != 0)
                answer[idx++] = board[i][j];
        }
    }

    return answer;
}