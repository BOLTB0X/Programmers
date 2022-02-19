#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int board[1000][1000];
//달팽이 방향
const int dy[3] = {1, 0, -1};
const int dx[3] = {0, 1, -1};

//초기화
void init(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
            board[i][j] = 0;
    }
    return;
}

//범위 체크
int in_Range(int y, int x, int n) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

int* solution(int n) {
    //기본 세팅
    int number = 1, y = 0, x = 0;
    init(n);
    
    //반복문으로 달팽이 방식으로 진행
    while(in_Range(y, x, n) == 1 && board[y][x] == 0) {
        for (int dir = 0; dir < 3; ++dir) {
            if (in_Range(y, x, n) == 0 || board[y][x] != 0)
                break;
            
            while(1) {
                board[y][x] = number++;
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                
                if (in_Range(ny, nx, n) == 0 || board[ny][nx] != 0) {
                    y += dy[(1 + dir) % 3];
                    x += dx[(1 + dir) % 3];
                    break;
                }
                
                y = ny, x = nx;
            }
        }
    }
    
    int* answer = (int*)calloc(n * (n+1) / 2, sizeof(int));
    int answer_idx = 0;
    //정답 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != 0)
                answer[answer_idx++] = board[i][j];
        }
    }
    
    return answer;
}
