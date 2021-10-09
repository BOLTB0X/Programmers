#include <string>
#include <vector>

using namespace std;

//������ ���� ����
int supoja1[5] = {1, 2, 3, 4, 5};
int supoja2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int supoja3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

//�ִ�
int max(int a, int b) {
    return a > b ? a : b;
}

vector<int> solution(vector<int> answers) {
    vector<int> result;
    int score[3] = { 0, };
    int max_score = 0;
    
    //���交�͸�ŭ ��ȸ
    for (int i = 0; i < answers.size(); ++i) {
        //i%5,8,10���� ������ �� ��ġ�� ī��Ʈ
        if (answers[i] == supoja1[i % 5])
            score[0]++;
        if (answers[i] == supoja2[i % 8])
            score[1]++;
        if (answers[i] == supoja3[i % 10])
            score[2]++;
    }

    //���� �ְ� ������ ��������
    max_score = max(max(score[0], score[1]), score[2]);
    
    //���交�Ϳ� ����
    for (int i = 0; i < 3; ++i) {
        //�ְ������ڸ� ã����
        if (max_score == score[i]) {
            //idx+1�̹Ƿ�
            result.push_back(i + 1);
        }
    }
    //���� ��ȯ
    return result;
}