#include <string>
#include <vector>

using namespace std;

int cnt = 0; // 카운트
vector<int> adj[101];
vector<int> visited;
vector<int> mash(2,0);

// 최소
int Min(int a, int b) {
    return a < b ? a : b;
}

// 절댓값
int Abs(int a) {
    return a < 0 ? -a : a;
}

// 그래프 탐색
void DFS(int n, int cur, int y, int x) {
    visited[cur] = 1;
    mash[cnt]++;
    
    for (int&next : adj[cur]) {
        // 금지 노드
        if ((next == y && cur == x) || (next == x && cur == y))
            continue;
        // 재방지 방문
        if (visited[next] == 1)
            continue;
        
        // 호출
        DFS(n, next, y, x);
    }
    return;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9; // 최솟값을 위한

    for(auto& w: wires) {
        adj[w[0]].push_back(w[1]);
        adj[w[1]].push_back(w[0]);
    }
    
    // 연결을 끊을 노드 
    for (auto& w: wires) {
        visited = vector(n+1, 0); // 초기화
        cnt = 0; // 초기화
        mash = vector(2, 0); // 초기화
        int y = w[0];
        int x = w[1];
        
        // DFS로 탐색
        for (int i = 1; i <= n; ++i) {
            // 재방문 방지
            if (visited[i] == 1)
                continue;
            
            DFS(n, i, y, x);
            cnt++;
        }
        // 둘로 나눠졌다면
        if (cnt == 2)
            answer = Min(answer, Abs(mash[0] - mash[1]));
    }
    
    return answer;
}
