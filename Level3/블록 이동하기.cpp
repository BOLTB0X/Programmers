#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
    int y1, x1, y2, x2;
} Node;

vector<vector<int>> nboard;
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//���ư� ���� 
vector<Node> get_Next(Node cur) {
    vector<Node> next;

    // 4���� Ȯ��
    for (int dir = 0; dir < 4; ++dir) {
        int ny1 = cur.y1 + dy[dir];
        int nx1 = cur.x1 + dx[dir];
        int ny2 = cur.y2 + dy[dir];
        int nx2 = cur.x2 + dx[dir];

        // �������� ����ִ� ���
        if (nboard[ny1][nx1] == 0 && nboard[ny2][nx2] == 0)
            next.push_back({ ny1, nx1, ny2, nx2 });
    }

    // ���ο� ���� ��
    int hor[2] = { -1,1 };
    if (cur.y1 == cur.y2) {

        // �������� ȸ���ϰų�, �Ʒ������� ȸ��
        for (int dir = 0; dir < 2; ++dir) {
            // ���� Ȥ�� �Ʒ��� �� ĭ�� ��� ��� �ִٸ�
            if (nboard[cur.y1 + hor[dir]][cur.x1] == 0 && nboard[cur.y2 + hor[dir]][cur.x2] == 0) {
                next.push_back({ cur.y1, cur.x1, cur.y1 + hor[dir], cur.x1 });
                next.push_back({ cur.y2, cur.x2, cur.y2 + hor[dir], cur.x2 });
            }
        }
    }
    
    // ���ο� ���� ��
    int ver[2] = { -1,1 };
    if (cur.x1 == cur.x2) {

        // �������� ȸ���ϰų�, �Ʒ������� ȸ��
        for (int dir = 0; dir < 2; ++dir) {
            // ���� Ȥ�� �Ʒ��� �� ĭ�� ��� ��� �ִٸ�
            if (nboard[cur.y1][cur.x1 + ver[dir]] == 0 && nboard[cur.y2][cur.x2 + ver[dir]] == 0) {
                next.push_back({ cur.y1, cur.x1, cur.y1, cur.x1 + ver[dir] });
                next.push_back({ cur.y2, cur.x2, cur.y2, cur.x2 + ver[dir] });
            }
        }
    }

    return next;
}

int BFS(int n) {
    vector<Node> visited; // �湮����Ʈ
    queue<pair<Node,int>> que;
    que.push({ {1,1,1,2 }, 0 });
    visited.push_back({ 1,1,1,2 });

    // ť�� �����������
    while (!que.empty()) {
        Node cur = que.front().first;
        int dist = que.front().second;
        que.pop();

        // ������ ���
        if ((cur.y1 == n && cur.x1 == n) || (cur.y2 == n && cur.x2 == n))
            return dist;

        // ���� ��ġ���� �̵��� �� �ִ� ��ġ
        vector<Node> next = get_Next(cur);

        for (Node& ne : next) {
            int flag = 1;
            // ��湮���� Ȯ��
            for (Node& v : visited) {
                //��湮�̸�
                if (ne.y1 == v.y1 && ne.x1 == v.x1 && ne.y2 == v.y2 && ne.x2 == v.x2) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                que.push({ ne, dist + 1 });
                visited.push_back(ne);
            }
        }
    }
    return 0;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size(); // ����
    
    // ������ �ܰ��� ���� �δ� ���·� ��ȯ
    nboard.resize(n + 2, vector<int>(n + 2, 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            nboard[i + 1][j + 1] = board[i][j];
    }
    //�ʺ�켱 �̿�
    answer = BFS(n);

    return answer;
}