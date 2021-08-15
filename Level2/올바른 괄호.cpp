#include<string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = false;
    // '('=1, ')'=-1
    int tmp = 0;
    for (int i = 0; i < s.length(); i++) {
        if (tmp < 0) {
            answer = false;
            break;
        }
        else {
            if (s[i] == '(') tmp += 1;
            else if (s[i] == ')') tmp -= 1;
        }
    }
    if (tmp == 0) answer = true;
    else answer = false;
    
    return answer;
}