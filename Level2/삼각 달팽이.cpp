#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board;

const int dy[3] = { 1,0,-1 };
const int dx[3] = { 0,1,-1 };

int in_Range(int y, int x, int n) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

vector<int> solution(int n) {
    vector<int> answer;
    board.resize(n, vector<int>(n, 0));
    int number = 1, cy = 0, cx = 0;

    while (in_Range(cy, cx, n) == 1 && board[cy][cx] == 0) {
        for (int dir = 0; dir < 3; ++dir) {
            if (in_Range(cy, cx, n) == 0 || board[cy][cx] != 0)
                break;

            while (1) {
                board[cy][cx] = number++;
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];

                if (in_Range(ny, nx, n) == 0 || board[ny][nx] != 0) {
                    cy += dy[(1 + dir) % 3];
                    cx += dx[(1 + dir) % 3];
                    break;
                }

                cy = ny, cx = nx;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != 0)
                answer.push_back(board[i][j]);
        }
    }
    return answer;
}
