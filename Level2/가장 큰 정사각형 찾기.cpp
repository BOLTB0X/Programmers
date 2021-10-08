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
            if (board[i][j] == 1) {
                board[i][j] = min(board[i][j - 1], board[i - 1][j]);
                board[i][j] = min(board[i - 1][j - 1], board[i][j]) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}