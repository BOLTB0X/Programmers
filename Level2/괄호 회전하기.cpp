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

//괄호가 올바른지 체크
int is_Correct(string str) {
    int size = str.length(); //길이
    
    //스택을 이용하며 탐색 시작
    for (int i =0; i < size; ++i) {
        //열림이면
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            push(str[i]);
        else {
            //pop을 할 수 있는 경우들
            if (str[i] == ')' && stack[top] == '(')
                pop();
            else if (str[i] == '}' && stack[top] == '{')
                pop();
            else if (str[i] == ']' && stack[top] == '[')
                pop();
            //맞지 않다면 -> 올바른 X
            else
                return 0;
        }
    }
    //스택이 비어있지 않다면 올바르지 X
    if (top != -1)
        return 0;
    return 1;
}

//문자열 회전
string rotate_str(string str) {
    int size = str.length();
    char tmp = str[0];
    
    //왼쪽으로 회전
    for (int i = 1; i < size; ++i) 
        str[i - 1] = str[i];
    
    str[size - 1] = tmp;
    
    return str;
}

int solution(string s) {
    int answer = 0;
    int size = s.length();
    
    if (is_Correct(s) == 1) 
        answer++;
    
    for (int i = 1; i <size; ++i) {
        s = rotate_str(s); //왼쪽으로 회전
        top = -1; //스택 초기화
        
        //올바른 가?
        if (is_Correct(s) == 1)
            answer++;
    }
    
    return answer;
}
