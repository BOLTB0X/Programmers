#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[20001];
int dist[20001] = { 0, };
bool visited[20001];

//BFS로 그래프 탐색
int BFS(void) {
    int max_value = -1;
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            //미방문이면
            if (!visited[next]) {
                dist[next] = dist[cur] + 1;
                visited[next] = true;
                q.push(next);
                if (dist[next] > max_value) {
                    max_value = dist[next];
                }
            }
        }
    }
    return max_value;
}

int count_max(int max_value, int n) {
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (max_value == dist[i])
            cnt++;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    //무향그래프 생성
    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    int max_dist = BFS();
    answer = count_max(max_dist, n);
    return answer;
}