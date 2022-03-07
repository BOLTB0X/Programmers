#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//상하좌우
int visited[501][501][4];
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//초기화
void init(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int dir = 0; dir < 4; ++dir)
                visited[i][j][dir] = 0;
        }
    }
    return;
}

//방향 변환
int turn_dir(char cmd, int dir) {
    //좌회전 해야하는 경우
    if (cmd == 'L') {
        if (dir == 0)
            return 3;
        else if (dir == 1)
            return 2;
        else if (dir == 2)
            return 0;
        else if (dir == 3)
            return 1;
    }

    //우회전
    else {
        if (dir == 0)
            return 2;
        else if (dir == 1)
            return 3;
        else if (dir == 2)
            return 1;
        else if (dir == 3)
            return 0;
    }
}

//DFS처럼 사용
int recursive_simulation(vector<string>& grid, int n, int m, int y, int x, int d, int cycle) {
    //다시 돌아온다면
    if (visited[y][x][d] == 1)
        return cycle;

    visited[y][x][d] = 1;
    int ny = y, nx = x, nd = d;

    //직진이 아닌 경우
    if (grid[y][x] != 'S')
        nd = turn_dir(grid[y][x], d);

    ny = y + dy[nd];
    nx = x + dx[nd];

    //범위 내로 조절
    if (ny < 0) ny = n - 1;
    if (nx < 0) nx = m - 1;
    if (ny >= n) ny = 0;
    if (nx >= m) nx = 0;

    return recursive_simulation(grid, n, m, ny, nx, nd, cycle + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int row = grid.size(); //행 
    int col = grid[0].size(); //열

    init(row, col); //방문리스트 초기화

    //사이클이 생기는 알기위해 각 지점마다 재귀로 시뮬레이션을 돌려봄
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            for (int dir = 0; dir < 4; ++dir) {
                int cycle = recursive_simulation(grid, row, col, i, j, dir, 0);
                //사이클이 생겼다면
                if (cycle != 0)
                    answer.push_back(cycle);
            }
        }
    }
    //오름차순 정렬
    sort(answer.begin(), answer.end());
    return answer;
}
