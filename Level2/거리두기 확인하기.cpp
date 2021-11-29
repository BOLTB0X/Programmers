#include <string>
#include <vector>

using namespace std;

//�����¿�
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//üũ��
bool flag;

//���̿켱Ž��
void DFS(vector<string>& place, vector<vector<bool>>& visited, int y, int x, int depth) {
    //���������� Ž��
    for (int dir = 0; dir < 4; ++dir) {
        //���̰� 2�̴��� ���̸�
        if (depth == 2 || flag)
            return;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        //���� ��
        if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5) {
            //����
            if (!visited[ny][nx] && place[ny][nx] != 'X') {
                //�ڸ���
                if (place[ny][nx] == 'P') {
                    flag = true;
                    return;
                }
                else {
                    visited[ny][nx] = true;
                    DFS(place, visited, ny, nx, depth + 1);
                }
            }
        }
    }
    return;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    //�� ���� 
    for (auto& place : places) {
        //�湮����Ʈ ���� �� �ʱ�ȭ
        vector<vector<bool>> visited(5, vector<bool>(5, false));
        flag = false;
        //�� ���� ĭ�� Ȯ��
        for (int i = 0; i < place.size(); ++i) {
            for (int j = 0; j < place[i].size(); ++j) {
                //�̹湮�̰� �¼��� �߰��ϸ�
                if (!visited[i][j] && place[i][j] == 'P') {
                    visited[i][j] = true;
                    DFS(place, visited, i, j, 0);
                }
                //�Ÿ��α⸦ ��Ű�� �ʾ����Ƿ�
                if (flag) {
                    answer.push_back(0);
                    break;
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            answer.push_back(1);
    }
    
    //��ȯ
    return answer;
}