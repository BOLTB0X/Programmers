#include <string>
#include <vector>

using namespace std;

long long answer = 0;
vector<long long> adj[300001]; //인접리스트로 변경

long long Abs(long long a) {
    return a < 0 ? -a : a;
}

void DFS(vector<long long>& tot, int cur, int par) {
    for (long long& next : adj[cur]) {
        if (next != par) //부모노드랑 다르다면
            DFS(tot, next, cur);
    }
    
    // DFS 다 탐색 이후
    tot[par] += tot[cur];
    answer += Abs(tot[cur]);

    return;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long size = a.size();
    vector<long long> tot(size, 0); //long long
    
    for (long long i = 0; i < size; ++i)
        tot[i] = a[i];
    
    //인접리스트로 변경
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    DFS(tot, 0, 0); //깊이우선탐색

    if (tot[0] == 0)
        return answer;
    
    return -1;
}
