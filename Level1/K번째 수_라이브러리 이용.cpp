#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//���� �����̵�
int vector_sliding(vector<int>& array, int start, int end, int idx) {
    //comm�� 3���� ����
    vector<int> partial_arr;

    //Ž��
    for (int i = start - 1; i < end; ++i)
        partial_arr.push_back(array[i]);

    //�������� ����
    sort(partial_arr.begin(), partial_arr.end());

    //Ÿ�� ��ȯ
    return partial_arr[idx - 1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    //�迭�� �߶����
    for (int i = 0; i < commands.size(); ++i) {
        //���� �����̵��� �Ͽ� �ش� ���� ���� ��
        int ret = vector_sliding(array, commands[i][0], commands[i][1], commands[i][2]);
        //���� ���Ϳ� ����
        answer.push_back(ret);
    }
    return answer;
}