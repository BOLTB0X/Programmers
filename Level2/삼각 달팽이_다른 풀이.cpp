#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    //격자판 생성
    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));

    int max_number = (n * (n + 1)) / 2;
    int top = 1, bottom = n;
    int left = 1, right = 0;

    int number = 1, dir = 0;

    //시뮬 시작
    while (number <= max_number) {
        //대각선으로 진행
        if (dir == 0) {
            for (int i = top; i <= bottom; ++i) 
                board[i][left] = number++;
            top++, left++, dir = 1;
        }
        // - > 진행
        else if (dir == 1) {
            for (int i = left; i <= bottom - right; ++i)
                board[bottom][i] = number++;
            bottom--;
            dir = 2;
        }
        // 위러 진행
        else if (dir == 2) {
            for (int i = bottom; i >= top; --i)
                board[i][i - right] = number++;
            right++, top++;
            dir = 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            if (board[i][j] != 0)
                answer.push_back(board[i][j]);
    }
    return answer;
}