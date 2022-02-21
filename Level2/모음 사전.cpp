#include <string>
#include <vector>
#include <algorithm> //정렬용

using namespace std;

vector<string> per;
char moum[5] = { 'A', 'E', 'I', 'O', 'U' };

void DFS(string word, int leng) {
    //탈출조건
    if (word.length() == leng) {
        per.push_back(word);
        return;
    }

    //중복순열처럼 
    for (char& m : moum)
        DFS(word + m, leng);
    return;
}

int solution(string word) {
    int answer = 0;

    //각 백트래킹으로 순열로 나올 모든 단어 조합을 구합
    for (int i = 1; i <= 5; ++i) {
        string tmp_word = "";
        DFS(tmp_word, i);
    }

    //단어 순열이 A, E, I ..... AA 등 섞여있어 정렬이 필요
    sort(per.begin(), per.end());

    for (int i = 0; i < per.size(); ++i) {
        if (word == per[i]) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}