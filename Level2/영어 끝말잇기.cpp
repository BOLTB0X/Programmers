#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    bool check=true;

    for (int i = 1; i < words.size(); i++) {
        //중복 검사
        for (int j = 0; j < i; j++) {
            if (words[j] == words[i]) {
                check = false;
                break;
            }
        }
        string prev = words[i - 1];
        string cur = words[i];
        //끝말잇기가 틀린다면
        if (prev[prev.length() - 1] != cur[0]) {
            check = false;
        }
        if (!check) {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            return answer;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}