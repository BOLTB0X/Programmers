#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    //체크용
    bool flag = true;
    
    //완전탐색 시작
    for (int i=1;i<words.size();++i) {
        //중복검사
        for (int j=0;j<i;++j) {
            if (words[j] == words[i]) {
                flag = false;
                break;
            }
        }
        //틀린 사람 발생
        if (!flag) {
            answer.push_back((i%n)+1);
            answer.push_back(((int)i/n)+1);
            break;
        }
        
        //발생되지 않으면 또 틀린 사람이 있는지 확인
        string cur = words[i];
        string prev = words[i-1];
        
        //틀림 발생
        if (cur[0] != prev[prev.length()-1]) {
            flag = false;
            answer.push_back((i%n)+1);
            answer.push_back(((int)i/n)+1);
            break;
        }
    }
    
    //아무도 안틀렸다면
    if (flag) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
