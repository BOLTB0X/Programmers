#include <string>
#include <vector>

using namespace std;

//수포자 정답 패턴
int supoja1[5] = {1, 2, 3, 4, 5};
int supoja2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int supoja3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

//최대
int max(int a, int b) {
    return a > b ? a : b;
}

vector<int> solution(vector<int> answers) {
    vector<int> result;
    int score[3] = { 0, };
    int max_score = 0;
    
    //정답벡터만큼 순회
    for (int i = 0; i < answers.size(); ++i) {
        //i%5,8,10패턴 같으면 각 위치에 카운트
        if (answers[i] == supoja1[i % 5])
            score[0]++;
        if (answers[i] == supoja2[i % 8])
            score[1]++;
        if (answers[i] == supoja3[i % 10])
            score[2]++;
    }

    //셋중 최고 점수가 몇점인지
    max_score = max(max(score[0], score[1]), score[2]);
    
    //정답벡터에 삽입
    for (int i = 0; i < 3; ++i) {
        //최고점수자를 찾으면
        if (max_score == score[i]) {
            //idx+1이므로
            result.push_back(i + 1);
        }
    }
    //정답 반환
    return result;
}