#include <string>
#include <vector>

using namespace std;

//수포자들 패턴
int style1[5] = { 1,2,3,4,5 };
int style2[8] = { 2,1,2,3,2,4,2,5 };
int style3[10] = { 3,3,1,1,2,2,4,4,5,5 };

//최댓값 반환
int max(int a, int b) {
    return a > b ? a : b;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    //순서대로 수포자들의 점수
    int score[3] = { 0, };
    int max_score;

    //정답을 차례로 수포자들의 스타일과 비교하며
    //점수를 매김
    for (int i = 0; i < answers.size(); ++i) {
        //각 스타일에 맞다면
        if (answers[i] == style1[i % 5])
            score[0]++;
        if (answers[i] == style2[i % 8])
            score[1]++;
        if (answers[i] == style3[i % 10])
            score[2]++;
    }

    //셋중 최댓값
    max_score = max(max(score[0], score[1]), score[2]);

    //미지막으로 문제조건에 맞게
    for (int i = 0; i < 3; ++i)
        if (max_score == score[i])
            answer.push_back(i + 1);
    
    //반환
    return answer;
}
