#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//�ӽ� ����
vector<string> tmp;

//���� �켱 Ž��
bool DFS(vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& answer, string cur_ticket, int depth) {
    //���� Ƽ�� ���� ���Ϳ� ����
    tmp.push_back(cur_ticket);

    //���� ���̰� ��ü Ƽ�Ϻ����� ���̱��� �����ϸ�
    if (depth == tickets.size()) {
        answer = tmp;
        return true;
    }
    //���� Ƽ���� ������ Ž�� ����
    for (int i = 0; i < tickets.size(); ++i) {
        //�� ���� ù ��° ���� ��� Ƽ���̰� �̹湮�̸�
        if (tickets[i][0] == cur_ticket && !visited[i]) {
            //�湮 ó��
            visited[i] = true;
            //�ٽ� DFS�� Ž�� ����
            bool is_success = DFS(tickets, visited, answer, tickets[i][1], depth + 1);
            //������ ���� �ϸ� ������ ��� ����
            //false�� �ߴܽ�Ŵ
            if (is_success)
                return true;
            visited[i] = false;
        }
    }
    //���� �ȱ׷��� �ߺ�
    tmp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    //���交��
    vector<string> answer;

    //�湮����Ʈ ���� �� �ʱ�ȭ
    vector<bool> visited(tickets.size(), false);

    //���ĺ� ������ ����
    sort(tickets.begin(), tickets.end());

    //�ٸ� DFS�� �ٸ��� ��� Ƽ���� �����.
    //�׻� "ICN" ���׿��� ���
    DFS(tickets, visited, answer, "ICN", 0);
    return answer;
}