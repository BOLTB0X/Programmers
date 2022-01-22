#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int num = stages.size();
    //�� �÷��̾��� �������� ������
    map<int, int> dict;
    //������
    vector<pair<int, double>> fails;

    //�������� �������� üũ
    //���� KEY���� N�� �Ѵ� ���� �� Ŭ��� �ߴٴ� ��
    //������ ���� �� ��� X
    for (int i = 0; i < num; ++i)
        dict[stages[i]]++;

    for (int i = 1; i <= N; ++i) {
        //������ ������ ���� ���� �������� 0���� ���
        if (dict[i] == 0) {
            fails.push_back({ i, 0 });
            continue;
        }
        fails.push_back({ i, (double)dict[i] / num });
        num -= dict[i];
    }
    //������ �������� �������� ����
    sort(fails.begin(), fails.end(), compare);

    //���������� ���交�Ϳ� ����
    for (int i = 0; i < N; ++i)
        answer.push_back(fails[i].first);
    return answer;
}