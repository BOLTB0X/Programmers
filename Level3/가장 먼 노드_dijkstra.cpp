#include <string>
#include <vector>
#include <queue>

using namespace std;

//가장 먼 노드의 갯수
int max_cnt = 0;

//다익스트라
void dijkstra(vector<int> graph[], vector<bool>& visited, int* dist, int cur) {
    queue<pair<int, int>> q;
    q.push({ cur,1 });

    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        //탐색
        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i];
            
            //재방문이면
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
    //무향그래프 생성
    vector<int> graph[20001];
    //방문리스트 생성 및 초기화
    vector<bool> visited(edge.size(), false);
    //거리 배열 동적할당 생성
    int* dist = new int[n + 1];

    for (int i = 1; i <= n; ++i) {
        //각 거리에 최댓값 대입
        dist[i] = 0x7fffffff;
    }

    //2차원 벡터 엣지 정보를 그래프로 넘김
    //열은 2로 고정
    for (int i = 0; i < edge.size(); ++i) {
        //무향그래프
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    //첫 스타트 0으로 시작
    dist[1] = 0;
    //다익스트라로 노드 탐색
    dijkstra(graph,visited,dist,1);
    
    //최대 갯수 탐색
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == max_cnt)
            answer++;
    }

    //정답 반환
    return answer;
}