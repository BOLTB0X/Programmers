#include <string>
#include <vector>

using namespace std;

//게시판
vector<vector<int>> board;

//달팽이식 이동방향
const int dy[3] = {1, 0, -1};
const int dx[3] = {0, 1, -1};

//범위
int in_Range(int n, int y, int x) {
    return 1<= y && y <= n && 1<= x && x <= n;
}

vector<int> solution(int n) {
    vector<int> answer;
    board.resize(n + 1, vector<int>(n + 1, 0));
    int number = 1;
    int y = 1, x = 1;
    
    //시뮬
    while(in_Range(n, y, x) == 1 && board[y][x] == 0) {
        for (int dir =0; dir < 3; ++dir) {
            //탈출 조건
            if (in_Range(n, y, x) == 0 || board[y][x] != 0)
                break;
            
            while(1) {
                board[y][x] = number++;
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                
                //탈출 조건
                if (in_Range(n, ny, nx) == 0 || board[ny][nx] != 0) {
                    y += dy[(1 + dir) % 3];
                    x += dx[(1 + dir) % 3];
                    break;
                }
                
                y = ny, x = nx;
            }
        }
    }
    
    //답 삽입
    for (int i=1; i<=n;++i) {
        for (int j=1; j <=n; ++j) {
            if (board[i][j] != 0)
                answer.push_back(board[i][j]);
        }
    }
    
    return answer;
}
