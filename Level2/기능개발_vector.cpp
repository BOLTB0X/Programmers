#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, works;
    int size = progresses.size(); //����

    //���� ������ ���
    for (int i = 0; i < size; ++i) {
        int p = 100 - progresses[i];
        if (p % speeds[i] == 0)
            works.push_back(p / speeds[i]);
        else
            works.push_back((p / speeds[i]) + 1);
    }

    int cmp = works[0], cnt = 1; //�񱳿�, ����

    for (int i = 1; i < size; ++i) {
        //�տ��� �� ������ ���� ���
        if (cmp >= works[i])
            cnt++;
        else {
            //���� �� �񱳶� ���� �����Ǵ� ���α׷� ���� �ʱ�ȭ
            answer.push_back(cnt);
            cnt = 1; //�ʱ�ȭ
            cmp = works[i];
        }
    }

    //�������� ó���� �ȵǹǷ�
    answer.push_back(cnt);
    return answer;
}