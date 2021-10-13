#include <string>
#include <vector>
#include <queue>

using namespace std;

//너비 우선 탐색
int BFS(vector<int> graph[], vector<int>& dist) {
    queue<int> q;
    int max_dist = -1;

    //1번 노드 부터 시작
    q.push(1);
    //방문처리
    dist[1] = 0;

    //큐가 빌때가지
    while (!q.empty()) {
        //최상단 뽑음
        int cur = q.front();
        q.pop();

        //현재 노드의 연결되어있는 수 만큼 
        for (int i = 0; i < graph[cur].size(); ++i) {
            //다음 노드
            int next = graph[cur][i];

            //재방문인 경우
            if (dist[next] != -1)
                continue;

            //진행할 노드에 거리정보 저장
            dist[next] = dist[cur] + 1;
            q.push(next);

            //가장 큰 거리인지 체크
            if (dist[next] > max_dist)
                max_dist = dist[next];
        }
    }
    //가장 큰 거리 반환
    //실제로 -1 더해진 값임
    return max_dist;
}

//가장 큰 거리 길이를 갖은 노드 탐색
int count_max_dist_node(vector<int>& dist, int max_dist) {
    int cnt = 0;
    //1부터 시작했으므로
    for (int i = 2; i <= dist.size(); ++i) {
        //큰 값을 발견하면
        if (dist[i] == max_dist)
            cnt++;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    //무향 그래프 생성
    vector<int> graph[20001];
    //거리정보를 담는 벡터 생성 및 -1로 초기화
    vector<int> dist(edge.size() + 1, -1);

    //2차원 벡터 엣지 정보를 그래프로 넘김
    //열은 2로 고정
    for (int i = 0; i < edge.size(); ++i) {
        //무향그래프
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    //BFS탐색으로 가장 먼 거리의 값 반환
    int max_dist = BFS(graph, dist);
    //해당 거리를 가진 노드가 몇개 인지 반환
    answer = count_max_dist_node(dist, max_dist);
    return answer;
}