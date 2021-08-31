#include <iostream>
#include <vector>
#include<string>
using namespace std;

int solution(string s) {
    int answer = -1;
    vector<char> v;
    for (int i = 0; i < s.length(); i++) {
        if (v.empty())
            v.push_back(s[i]);
        else {
            if (v[v.size() - 1] == s[i])
                v.pop_back();
            else
                v.push_back(s[i]);
        }
    }
    if (v.size() == 0) 
        answer = 1;
    else 
        answer = 0;
    return answer;
}