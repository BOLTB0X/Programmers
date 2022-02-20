#include <string>
#include <vector>
#define INF 0x7fffffff
#define ML 20001

using namespace std;

typedef struct {
    int pos, cost;
} Node;

Node que[ML];
int fr = 0, re = 0;

//push
void enqueue(Node data) {
    que[re++] = data;
    return;
}

//pop
Node dequeue(void) {
    return que[fr++];
}

vector<int> adj[ML]; //무향 인접리스트
vector<int> dist; //거리정보를 담는 벡터
vector<bool> visited; //방문리스트

//다익스트
int dijkstra(int start) {
    int max_dist = 0;
    //우선순위 큐 선언
    
    enqueue({ start, 1 });
    dist[start] = 1;
    visited[start] = 1; //출발지점

    while (fr < re) {
        Node cur = dequeue();

        //연결된 노드 순회
        for (int& next : adj[cur.pos]) {
            if (visited[next])
                continue;

            //갈 노드가 크다면 -> 진행 가능
            if (cur.cost + 1 < dist[next]) {
                dist[next] = cur.cost + 1;
                visited[next] = 1;

                //최대 거리 교체
                if (max_dist < cur.cost + 1)
                    max_dist = cur.cost + 1;
                enqueue({ next, cur.cost + 1 });
            }
        }
    }

    return max_dist;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    dist.resize(n + 1, INF); //최댓값으로 초기화
    visited.resize(n + 1, false); // 방문리스트 초기화

    //2차원 벡터 엣지 정보를 그래프로 넘김
    for (int i = 0; i < edge.size(); ++i) {
        //무향그래프
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }   

    //가장 먼 길이 반환 
    int max_dist = dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        if (dist[i] == max_dist)
            answer++;
    }

    //정답 반환
    return answer;
}
