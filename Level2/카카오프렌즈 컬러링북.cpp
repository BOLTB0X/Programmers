#include <vector>
#include <queue>

using namespace std;

//좌표
struct POS {
    int y, x;
};

//상하좌우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };

//너비우선탐색
int BFS(int m, int n, int y, int x, vector<vector<int>>& picture,vector<vector<bool>>& visited) {
    //큐 선언
    queue<POS> q;
    q.push({ y,x });
    //방문체크
    visited[y][x] = true;
    
    //초기화
    int area = 1;
    int type = picture[y][x];

    //BFS탐색 시작
    while (!q.empty()) {
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();

        //순차적으로 탐색
        for (int dir = 0; dir < 4; ++dir) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            //범위내
            if (ny >= 0 && nx >= 0 && ny < m && nx < n) {
                //미방문이고 색이 같다면
                if (!visited[ny][nx] && picture[ny][nx] == type) {
                    //사이즈 카운트
                    area++;
                    q.push({ ny,nx });
                    visited[ny][nx] = true;
                }
            }
        }
    }

    //반환
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    //방문리스트 초기화
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    //완전탐색 시작
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            //미방문이고 0이 아니면 BFS시작
            if (!visited[y][x] && picture[y][x] != 0) {
                int tmp_size = BFS(m, n, y, x, picture, visited);
                //카운트
                number_of_area++;
                //크다면
                if (tmp_size > max_size_of_one_area)
                    max_size_of_one_area = tmp_size;
            }
        }
    }

    //정답
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    //반환
    return answer;
}