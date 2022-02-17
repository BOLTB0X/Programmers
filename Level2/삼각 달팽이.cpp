#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board;

const int dy[3] = { 1,0,-1 };
const int dx[3] = { 0,1,-1 };

bool in_Range(int y, int x, int n) {
    return 1 <= y && y <= n && 1 <= x && x <= n;
}

vector<int> solution(int n) {
    vector<int> answer;
    board.resize(n + 1, vector<int>(n + 1, 0));
    int number = 1, cy = 1, cx = 1;

    while (in_Range(cy, cx, n) && board[cy][cx] == 0) {
        for (int dir = 0; dir < 3; ++dir) {
            if (!in_Range(cy, cx, n) || board[cy][cx] != 0)
                break;

            while (1) {
                board[cy][cx] = number++;
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];

                if (!in_Range(ny, nx, n) || board[ny][nx] != 0) {
                    cy += dy[(1 + dir) % 3];
                    cx += dx[(1 + dir) % 3];
                    break;
                }

                cy = ny, cx = nx;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (board[i][j] != 0)
                answer.push_back(board[i][j]);
        }
    }
    return answer;
}