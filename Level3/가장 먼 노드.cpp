#include <vector>
#include <queue>

using namespace std;

//무향그래프
vector<int> graph[20001];

//너비우선
int BFS(vector<bool>& visited, vector<int>& dist) {
    //최대 거리
    int max_dist = -1;

    queue<int> q;
    q.push(1);
    visited[1] = true;

    //큐가 비어질때 까지
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            //재방문인 경우
            if (visited[next])
                continue;
            //해당 정점의 거리 저장
            dist[next] = dist[cur] + 1;
            visited[next] = true;
            q.push(next);
            
            //크다면 교체
            if (dist[next] > max_dist)
                max_dist = dist[next];

        }
    }
    return max_dist;
}

//최대 거리 갯수 체크
int get_max_dist_count(int n, int max_value, vector<int>& dist) {
    int cnt = 0;
    //1부터 시작이므로 2부터 순회
    for (int i = 2; i <= n; i++) {
        if (max_value == dist[i])
            cnt++;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    //체크리스트 생성 및 초기화
    vector<bool> visited(edge.size() + 1, false);
    vector<int> dist(edge.size() + 1, 0);
    //edge벡터의 정보를 무향 그래프 생성


    //그래프에 삽입
    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    //BFS로 각 거리를 dist벡터에 저장
    int ret = BFS(visited, dist);
    answer = get_max_dist_count(n, ret, dist);

    return answer;
}
