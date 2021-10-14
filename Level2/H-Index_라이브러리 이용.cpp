#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    //�������� ����
    sort(citations.begin(), citations.end());

    //H-index�� ã�� ���� ���� ������� ���̷� �ʱ�ȭ
    //��������  n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰� 
    //������ ���� h�� ���� �ο�Ǿ��ٸ� h�� �ִ��� H-Index
    //�� �������� ������ �Ͽ� �ش� idx�� ũ�ų� ���� ��츦 ã���� ��
    //Ž��
    for (int i = 0; i < citations.size(); ++i) {
        int h_idx = citations.size() - i;
        if (h_idx <= citations[i]) {
            //ã���� ������ �극��ũ
            //������ ������ ��� �۾�����.
            answer = h_idx;
            break;
        }
    }
    //���� ��ȯ
    return answer;
}