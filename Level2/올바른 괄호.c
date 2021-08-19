#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
bool solution(const char* s) {
    bool answer = false;
    int tmp = 0;
    int s_size = strlen(s);

    for (int i = 0; i < s_size; i++) {
        if (tmp < 0) {
            answer = false;
            break;
        }
        else {
            if (s[i] == '(') tmp += 1;
            else if (s[i] == ')') tmp -= 1;
        }
    }
    if (tmp == 0)
        answer = true;
    else
        answer = false;
    return answer;
}