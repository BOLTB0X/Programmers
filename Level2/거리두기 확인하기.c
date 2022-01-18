#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int y, x, d;
} COOR;

COOR* que;
int head = 0, tail = 0;

void enqueue(COOR data) {
    que[tail++] = data;
    tail = tail % 26;
    return;
}

void dequeue(void) {
    head++;
    head = head % 26;
    return;
}

bool flag;
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

bool BFS(char** place, int y, int x) {
    bool visited[5][5];
    for (int l = 0; l < 5; ++l)
        memset(visited[l], 0, sizeof(bool) * 5);
    que = (COOR*)malloc(sizeof(COOR) * 26);
    head = 0;
    tail = 0;
    visited[y][x] = true;
    COOR tmp = { y,x,0 };
    enqueue(tmp);

    while (head != tail) {
        COOR cur = que[head];
        dequeue();

        for (int dir = 0; dir < 4; ++dir) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
                continue;
            if (visited[ny][nx] || place[ny][nx] == 'X')
                continue;
            if (place[ny][nx] == 'P') {
                if (cur.d + 1 <= 2) {
                    flag = false;
                    break;
                }
            }
            COOR next = { ny,nx, cur.d + 1 };
            enqueue(next);
            visited[ny][nx] = true;
        }
        if (!flag)
            break;
    }

    return flag;
}

int* solution(const char*** places, size_t places_rows, size_t places_cols) {
    int* answer = (int*)malloc(sizeof(int) * 5);

    for (int i = 0; i < 5; ++i) {
        flag = true;
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                if (places[i][j][k] == 'P') {
                    if (!BFS(places[i], j, k)) {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag)
                break;
        }
        if (!flag)
            answer[i] = 0;
        else
            answer[i] = 1;
    }
    return answer;
}