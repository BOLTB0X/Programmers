#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ML 1001

int board[ML][ML];
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
    int* answer = (int*)calloc(n * (n+1) / 2, sizeof(int));
    int number = 1, idx = 0, cy = 0, cx = 0;
    init(n); //초기화
    
    //삼각달팽이 형태로 진행
    while(in_Range(cy, cx, n) == 1 && board[cy][cx] == 0) {
        for (int dir = 0; dir < 3; ++dir) {
            //탈출조건
            if (!in_Range(cy, cx, n) || board[cy][cx] != 0)
                break;
            
            //한 방향으로
            while(1) {
                board[cy][cx] = number++;
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                
                //탈출 조건
                if (in_Range(ny, nx, n) == 0 || board[ny][nx] != 0) {
                    cy += dy[(1 + dir) % 3];
                    cx += dx[(1 + dir) % 3];
                    break;
                }
        
                cy = ny, cx = nx; //교체
            }
        }
    }
    
    //정답 삽입
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != 0) //삼각달팽이 원소 삽입 
                answer[idx++] = board[i][j];
        }
    }
    
    return answer;
}
