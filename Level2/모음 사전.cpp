#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char moum[5] = { 'A', 'E', 'I', 'O', 'U' }; //모음
vector<string> per;

//깊이우선탐색으로 백트래킹
void DFS(string word, int size) {
    //탈출 조건
    if (size == word.length()) {
        per.push_back(word);
        return;
    }

    for (char& m : moum)
        DFS(word + m, size);

    return;
}

int solution(string word) {
    int answer = 0;

    //중복순열을 구해야함
    for (int i = 1; i <= 5; ++i) {
        string alp = "";
        DFS(alp, i);
    }

    //정렬
    sort(per.begin(), per.end());

    //해당 단어가 몇번째인지 체크
    for (int i = 0; i < per.size(); ++i) {
        if (word == per[i]) {
            answer = i + 1; //인덱스 + 1
            break;
        }
    }
    //반환
    return answer;
}
