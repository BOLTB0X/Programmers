#include <string>
#include <vector>
#include <queue>

using namespace std;

//���� �� ����� ����
int max_cnt = 0;

//���ͽ�Ʈ��
void dijkstra(vector<int> graph[], vector<bool>& visited, int* dist, int cur) {
    queue<pair<int, int>> q;
    q.push({ cur,1 });

    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        //Ž��
        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i];
            
            //��湮�̸�
            if (visited[next])
                continue;
            if (cnt + 1 < dist[next]) {
                dist[next] = cnt + 1;
                visited[next] = true;
                if (max_cnt < cnt + 1)
                    max_cnt = cnt + 1;
                q.push({ next,cnt + 1 });
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    //����׷��� ����
    vector<int> graph[20001];
    //�湮����Ʈ ���� �� �ʱ�ȭ
    vector<bool> visited(edge.size(), false);
    //�Ÿ� �迭 �����Ҵ� ����
    int* dist = new int[n + 1];

    for (int i = 1; i <= n; ++i) {
        //�� �Ÿ��� �ִ� ����
        dist[i] = 0x7fffffff;
    }

    //2���� ���� ���� ������ �׷����� �ѱ�
    //���� 2�� ����
    for (int i = 0; i < edge.size(); ++i) {
        //����׷���
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    //ù ��ŸƮ 0���� ����
    dist[1] = 0;
    //���ͽ�Ʈ��� ��� Ž��
    dijkstra(graph,visited,dist,1);
    
    //�ִ� ���� Ž��
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == max_cnt)
            answer++;
    }

    //���� ��ȯ
    return answer;
}