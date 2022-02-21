#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int result = -1;
int visited[9]; //�湮����Ʈ

//�ʱ�ȭ
void init(int n) {
    for (int i = 0; i <= n; ++i)
        visited[i] = 0;
    return;
}

//���̿켱Ž��
void DFS(int** arr, int row, int score, int cur, int level) {
    //��ȸ
    for (int i = 0; i < row; ++i) {
        //�̹� �湮
        if (visited[i] == 1)
            continue;
        //�ּ� �ʿ䵵�� ū ���
        if (score < arr[i][0])
            continue;

        //���� ���� �� ���
        visited[i] = 1;
        DFS(arr, row, score - arr[i][1], i, level + 1);
        visited[i] = 0;
    }
   
    //���� ��ü
    if (result < level) 
        result =  level;
    return;
}

int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    int answer = -1;

    //�� �����̶� ��带 Ž��
    for (int i = 0; i < dungeons_rows; ++i) {
        //���� �Ƿε��� ũ��
        //���డ��
        if (k >= dungeons[i][0]) {
            init(dungeons_rows); //�湮 ����Ʈ �ʱ�ȭ
            visited[i] = 1; //üũ
            //DFS�� Ž�� ���̸� ����
            //Ž�� ���� == �ִ� ���� ��
            DFS(dungeons, dungeons_rows, k - dungeons[i][1], i, 1);
        }
    }

    //����
    answer = result;
    return answer;
}