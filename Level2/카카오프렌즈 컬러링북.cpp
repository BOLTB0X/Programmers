#include <vector>
#include <queue>

using namespace std;

//��ǥ
struct POS {
    int y, x;
};

//�����¿�
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };

//�ʺ�켱Ž��
int BFS(int m, int n, int y, int x, vector<vector<int>>& picture,vector<vector<bool>>& visited) {
    //ť ����
    queue<POS> q;
    q.push({ y,x });
    //�湮üũ
    visited[y][x] = true;
    
    //�ʱ�ȭ
    int area = 1;
    int type = picture[y][x];

    //BFSŽ�� ����
    while (!q.empty()) {
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();

        //���������� Ž��
        for (int dir = 0; dir < 4; ++dir) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            //������
            if (ny >= 0 && nx >= 0 && ny < m && nx < n) {
                //�̹湮�̰� ���� ���ٸ�
                if (!visited[ny][nx] && picture[ny][nx] == type) {
                    //������ ī��Ʈ
                    area++;
                    q.push({ ny,nx });
                    visited[ny][nx] = true;
                }
            }
        }
    }

    //��ȯ
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    //�湮����Ʈ �ʱ�ȭ
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    //����Ž�� ����
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            //�̹湮�̰� 0�� �ƴϸ� BFS����
            if (!visited[y][x] && picture[y][x] != 0) {
                int tmp_size = BFS(m, n, y, x, picture, visited);
                //ī��Ʈ
                number_of_area++;
                //ũ�ٸ�
                if (tmp_size > max_size_of_one_area)
                    max_size_of_one_area = tmp_size;
            }
        }
    }

    //����
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    //��ȯ
    return answer;
}