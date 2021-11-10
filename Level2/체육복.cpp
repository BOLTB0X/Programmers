#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //üũ�� ����
    vector<int> check(n, 1);

    //�Ҿ���� �л��� ����
    for (auto l : lost)
        check[l - 1]--;
    
    //������ �ִ� �л��� ����
    for (auto r : reserve)
        check[r - 1]++;

    //üũ ���� ��ȸ
    for (int i = 0; i < check.size(); ++i) {
        //���� �ش� �л��� ü������ ���ٸ�
        if (check[i] == 0) {
            //���� ��� Ȯ��
            if (i != 0 && check[i - 1] == 2) {
                check[i - 1]--;
                check[i]++;
            }  

            //���� ��� Ȯ��
            else if (i != check.size() - 1 && check[i + 1] == 2) {
                check[i + 1]--;
                check[i]++;
            }
        }
    }

    //������ ü������
    for (auto c : check)
        if (c != 0)
            answer++;

    //��ȯ
    return answer;
}