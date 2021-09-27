#include <string>
#include <vector>

using namespace std;
int ans1[5] = { 1, 2, 3, 4, 5 };
int ans2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int ans3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

//최대 
int max(int a, int b) {
    return a > b ? a : b;
}

vector<int> solution(vector<int> answers) {
    vector<int> result;
    //세 수포자
    int score[3] = { 0, };
    int max_score = 0;
    //완전탐색 시작
    for (int i = 0; i < answers.size(); i++) {
        //i%5,8,10패턴 같으면 각 위치에 카운트
        if (answers[i] == ans1[i % 5])
            score[0] += 1;
        if (answers[i] == ans2[i % 8])
            score[1] += 1;
        if (answers[i] == ans3[i % 10])
            score[2] += 1;
    }
    max_score = max(max(score[0], score[1]), score[2]);
    for (int i = 0; i < 3; i++) {
        //인덱스 이므로
        if (score[i] == max_score) {
            result.push_back(i + 1);
        }
    }
    return result;
}