#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//다익스트라
void dijkstra(vector<pair<int, int>> adj[], vector<int>& dist, int K) {
    //우선순위 큐 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 1,0 });

    while (!pq.empty()) {
        int pos = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[pos].size(); ++i) {
            int next = adj[pos][i].first;
            int nd = adj[pos][i].second;

            if (dist[next] > dist[pos] + nd) {
                dist[next] = dist[pos] + nd;
                pq.push({ next,nd });
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<pair<int, int>> adj[51];
    vector<int> dist(N + 1, 1e9);

    for (int i = 0; i < road.size(); ++i) {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }

    //셋팅
    dist[1] = 0;
    
    //다익스트라 호출
    dijkstra(adj, dist, K);

    //배달 가능한
    for (int i = 1; i < dist.size(); ++i)
        if (dist[i] <= K)
            answer++;
    return answer;
}