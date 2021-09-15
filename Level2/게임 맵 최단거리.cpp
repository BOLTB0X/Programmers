#include <vector>
#include <queue>

using namespace std;

int BFS(vector<vector<int>>& maps) {
    int n = maps.size(); // 행
    int m = maps[0].size(); // 열
    //진행방향
    const int dy[4] = { -1,0,1,0 };
    const int dx[4] = { 0,1,0,-1 };
    //방문및 거리 정보를 담는 배열
    int dist[101][101] = { 0, };

    queue<pair<int, int>> q;
    q.push({ 0,0 });
    dist[0][0] = 1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            //범위초과시
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            //재방문 및 벽인경우
            if (dist[ny][nx] != 0 || maps[ny][nx] == 0)
                continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ ny,nx });
        }
    }
    //도달하지 못할 경우
    if (dist[n - 1][m - 1] == 0)
        return -1;
    return dist[n - 1][m - 1];
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    answer = BFS(maps);
    return answer;
}