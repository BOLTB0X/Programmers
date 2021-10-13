#include <string>
#include <vector>
#include <queue>

using namespace std;

//�ʺ� �켱 Ž��
int BFS(vector<int> graph[], vector<int>& dist) {
    queue<int> q;
    int max_dist = -1;

    //1�� ��� ���� ����
    q.push(1);
    //�湮ó��
    dist[1] = 0;

    //ť�� ��������
    while (!q.empty()) {
        //�ֻ�� ����
        int cur = q.front();
        q.pop();

        //���� ����� ����Ǿ��ִ� �� ��ŭ 
        for (int i = 0; i < graph[cur].size(); ++i) {
            //���� ���
            int next = graph[cur][i];

            //��湮�� ���
            if (dist[next] != -1)
                continue;

            //������ ��忡 �Ÿ����� ����
            dist[next] = dist[cur] + 1;
            q.push(next);

            //���� ū �Ÿ����� üũ
            if (dist[next] > max_dist)
                max_dist = dist[next];
        }
    }
    //���� ū �Ÿ� ��ȯ
    //������ -1 ������ ����
    return max_dist;
}

//���� ū �Ÿ� ���̸� ���� ��� Ž��
int count_max_dist_node(vector<int>& dist, int max_dist) {
    int cnt = 0;
    //1���� ���������Ƿ�
    for (int i = 2; i <= dist.size(); ++i) {
        //ū ���� �߰��ϸ�
        if (dist[i] == max_dist)
            cnt++;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    //���� �׷��� ����
    vector<int> graph[20001];
    //�Ÿ������� ��� ���� ���� �� -1�� �ʱ�ȭ
    vector<int> dist(edge.size() + 1, -1);

    //2���� ���� ���� ������ �׷����� �ѱ�
    //���� 2�� ����
    for (int i = 0; i < edge.size(); ++i) {
        //����׷���
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    //BFSŽ������ ���� �� �Ÿ��� �� ��ȯ
    int max_dist = BFS(graph, dist);
    //�ش� �Ÿ��� ���� ��尡 � ���� ��ȯ
    answer = count_max_dist_node(dist, max_dist);
    return answer;
}