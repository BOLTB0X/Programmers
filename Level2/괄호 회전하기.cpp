#include <string>
#include <vector>

using namespace std;

char stack[1001]; //스택 정의
int top = -1;

void push(char data){
    stack[++top] = data;
    return;
}

void pop(void) {
    top--;
    return;
}

//왼쪽 방향 회전
string rotate_str(string s) {
    int size = s.length();
    char tmp = s[0];
    
    for (int i = 1;  i < size; ++i) 
        s[i - 1] = s[i];
    s[size - 1] = tmp;
    
    return s;
}

//올바른 지 체크
int is_correct(string s) {
    int size = s.length();
    
    for (int i = 0; i < size; ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(s[i]);
        else {
            if (s[i] == ')' && stack[top] == '(')
                pop();
            else if (s[i] == '}' && stack[top] == '{')
                pop();
            else if (s[i] == ']' && stack[top] == '[')
                pop();
            else
                return 0;
        }
    }
    //연산이 끝났는데도 스택이 비어지지 않았다면
    if (top != -1)
        return 0;
    return 1;
}

int solution(string s) {
    int answer = 0;
    int size = s.length();
    
    if (is_correct(s) == 1) 
        answer++;
    
    for (int i = 1; i < size; ++i) {
        s = rotate_str(s); //괄호 회전
        if (is_correct(s) == 1) //올바른가?
            answer++;
    }
    
    return answer;
}
