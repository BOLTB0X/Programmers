#include <string>
#include <vector>

using namespace std;

char st[1001];
int top = -1;

void push(char c) {
    st[++top] = c;
    return;
}

void pop(void) {
    top--;
    return;
}

//괄호가 올바르다면
int is_correct(string s) {
    top = -1;//초기화
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
            push(s[i]);
        }
        else {
            if (top == -1)
                return 0;
            else {
                if (s[i] == ']' && st[top] == '[')
                    pop();
                else if (s[i] == '}' && st[top] == '{')
                    pop();
                else if (s[i] == ')' && st[top] == '(')
                    pop();
            }
        }
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

string rotate_str(string s) {
    string ret = s;
    int size = ret.size();
    char tmp = ret[0];

    for (int i = 1; i < size; ++i)
        ret[i - 1] = ret[i];

    ret[size - 1] = tmp;
    return ret;
}

int solution(string s) {
    int answer = 0;
    int size = s.length();

    if (is_correct(s))
        answer++;

    for (int i = 1; i < size; ++i) {
        s = rotate_str(s);
        if (is_correct(s) == 1)
            answer++;
    }
    return answer;
}