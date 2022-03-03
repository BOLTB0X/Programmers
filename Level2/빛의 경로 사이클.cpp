#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> board; //시뮬용
int visited[501][501][4];

//상하좌우
const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };

//방향 전환
int trun_dir(char cmm, int dir) {
    if (cmm == 'L') {
        if (dir == 0)
            return 3;
        else if (dir == 1)
            return 2;
        else if (dir == 2)
            return 0;
        else if (dir == 3)
            return 1;
    }
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

//재귀를 통한 시뮬레이션
int recursive_simul(int n, int m, int y, int x, int dir, int len) {
    if (visited[y][x][dir] == 1)
        return len;

    visited[y][x][dir] = 1;

    int ny = y, nx = x, nd = dir;

    if (board[y][x] != 'S')
        nd = trun_dir(board[y][x], dir);
    ny = y + dy[nd];
    nx = x + dx[nd];

    if (ny < 0)
        ny = n - 1;
    if (nx < 0)
        nx = m - 1;
    if (ny == n)
        ny = 0;
    if (nx == m)
        nx = 0;

    return recursive_simul(n, m, ny, nx, nd, len + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int result = 0;
    int n = grid.size();
    int m = grid[0].size();

    board = grid;
    //완전탐색 시작
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                result = recursive_simul(n, m, i, j, k, 0);
                if (result != 0)
                    answer.push_back(result);
            }
        }
    }
    sort(answer.begin(), answer.end()); //오름차순 정렬

    return answer;
}