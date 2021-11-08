#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
    char* days[] = { "FRI", "SAT","SUN","MON", "TUE", "WED","THU" };

    // ������ ���� �޸𸮸� ���� �Ҵ����ּ���.
    char* answer = (char*)malloc(sizeof(days));

    int months[20] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int tot = 0;

    for (int i = 0; i < a - 1; i++) 
        tot += months[i];

    tot += b - 1;
    answer = days[tot % 7];

    return answer;
}