#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int result = -1;
int visited[9]; //방문리스트

//초기화
void init(int n) {
    for (int i = 0; i <= n; ++i)
        visited[i] = 0;
    return;
}

//깊이우선탐색
void DFS(int** arr, int row, int score, int cur, int level) {
    //순회
    for (int i = 0; i < row; ++i) {
        //이미 방문
        if (visited[i] == 1)
            continue;
        //최소 필요도가 큰 경우
        if (score < arr[i][0])
            continue;

        //진행 가능 한 경우
        visited[i] = 1;
        DFS(arr, row, score - arr[i][1], i, level + 1);
        visited[i] = 0;
    }
   
    //길이 교체
    if (result < level) 
        result =  level;
    return;
}

int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    int answer = -1;

    //각 던전이란 노드를 탐색
    for (int i = 0; i < dungeons_rows; ++i) {
        //현재 피로도가 크다
        //진행가능
        if (k >= dungeons[i][0]) {
            init(dungeons_rows); //방문 리스트 초기화
            visited[i] = 1; //체크
            //DFS로 탐사 길이를 구함
            //탐사 길이 == 최대 던전 수
            DFS(dungeons, dungeons_rows, k - dungeons[i][1], i, 1);
        }
    }

    //정답
    answer = result;
    return answer;
}