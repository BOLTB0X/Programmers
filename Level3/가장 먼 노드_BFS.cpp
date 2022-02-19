#include <string>
#include <vector>

using namespace std;

int que[20001];
int fr = 0, re = 0;

void enqueue(int data) {
    que[re++] = data;
    return;
}

int dequeue(void) {
    return que[fr++];
}

vector<int> adj[50001];
vector<int> dist;

//깊이우선탐색
int BFS(int n) {
    int max_dist = -1;
    enqueue(1);
    dist[1] = 0;
    
    //큐가 비어질때까지 
    while(fr < re) {
        int cur = dequeue();
        
        for (int& next: adj[cur]) {
            //재방문인 경우
            if (dist[next] != -1)
                continue;
            //거리 정보
            dist[next] = dist[cur] + 1;
            //최대인 경우 교체
            if (max_dist < dist[next])
                max_dist = dist[next];
            enqueue(next);
        }
    }
    
    return max_dist;
}

//가장 먼 노드 거리를 가진 개수 반환
int count_max_dist_Node(int max_value, int n) {
    int cnt = 0;
    for (int& d: dist) {
        if (max_value == d)
            cnt++;
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, size = edge.size();
    dist.resize(n + 1, -1);  
    
    //편의를 위한 그래프 생성
    for (int i = 0; i< size; ++i) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    int max_dist = BFS(n); //최대 거리 반환
    answer = count_max_dist_Node(max_dist, n); //개수 반환
    
    return answer;
}
