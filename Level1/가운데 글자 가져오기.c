#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* s) {
    //����
    char* answer;
    //���ڿ������Լ� �̿�
    int len = strlen(s);

    //���̰� ¦���� ���
    if (len % 2 == 0) {
        answer = (char*)malloc(3);
        answer[0] = s[len / 2 - 1];
        answer[1] = s[len / 2];
        answer[2] = '\0';
    }

    //Ȧ��
    else {
        answer = (char*)malloc(2);
        answer[0] = s[len / 2];
        answer[1] = '\0';
    }
    return answer;
}