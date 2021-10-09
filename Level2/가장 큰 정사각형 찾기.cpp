#include <iostream>
#include<vector>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int solution(vector<vector<int>> board) {
    int answer = board[0][0];

    int col = board[0].size();
    int row = board.size();

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            //0인 경우에는 정사각형이 만들어지지 않으므로 1인 경우만 계산
            if (board[i][j] == 1) {
                //왼쪽점, 위쪽점, 왼쪽 대각선에 있는 점 비교 수행
                board[i][j] = min(board[i][j - 1], board[i - 1][j]);
                board[i][j] = min(board[i - 1][j - 1], board[i][j]) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}
