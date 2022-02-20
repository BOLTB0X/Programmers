#include <string>
#include <vector>

using namespace std;

int que[20001];
int fr = 0, re = 0;

//push
void enqueue(int data) {
    que[re++] = data;
    return;
}

//pop
int dequeue(void) {
    return que[fr++];
}

vector<int> adj[50001];
vector<int> dist; // 거리 정보 저장용

//너비우선탐색
int BFS(int start) {
    int max_dist = 1;
    //1번으로 부터 멀리 떨어진 것이므로
    dist[start] = 1;
    enqueue(start);
    
    //큐가 빌때까지
    while (fr < re) {
        int cur = dequeue();
        
        //인접 노드 순회
        for (int& next: adj[cur]) {
            if (dist[next] != 0)
                continue;
            dist[next] = dist[cur] + 1;
            //최장 거리 교체
            if (dist[next] > max_dist)
                max_dist = dist[next];
            enqueue(next);
        }
    }
    
    return max_dist; //반환
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, size = edge.size();
    dist.resize(n + 1, 0);
    
    //인접리스트에 각 노드 정보를 확인
    for (int i = 0; i < size; ++i) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]); 
    }
    
    //최단경로로 이동했을 때 간선의 개수가 가장 많은 노드 -> BFS
    int max_dist = BFS(1);
    
    //1번을 제외한 최장 거리를 가진 노드 갯수 체크
    for (int i = 2; i <= n; ++i) {
        if (dist[i] == max_dist)
            answer++;
    }
    return answer;
}
