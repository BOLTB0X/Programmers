#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int stack[10001];
int top = -1;

void push(int data) {
    stack[++top] = data;
    top = top % 10001;
    return;
}

void pop(void) {
    top--;
    top = top % 10001;
    return;
}

int* solution(int prices[], size_t prices_len) {
    int* answer = (int*)malloc(sizeof(int) * prices_len);
    int answer_idx = 0;

    for (int i = 0; i < prices_len; ++i) {
        while (top != -1 && prices[stack[top]] > prices[i]) {
            answer[stack[top]] = i - stack[top];
            pop();
        }
        push(i);
    }
    while (top != -1) {
        answer[stack[top]] = prices_len - 1 - stack[top];
        pop();
    }
    return answer;
}