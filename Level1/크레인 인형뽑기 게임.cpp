#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;

    //이동 명령 하나씩 확인
    for (int i = 0; i < moves.size(); ++i) {
        int idx = moves[i] - 1;
        for (int j = 0; j<board.size();++j) {
            if (board[j][idx] != 0) {

                //비어있지 않고 삽입할 인형과 바구니 상단의 인형이 같다면
                if (!basket.empty() && basket.top() == board[j][idx]) {
                    basket.pop();
                    //득점
                    answer += 2;
                }
                //삽입
                else
                    basket.push(board[j][idx]);

                board[j][idx] = 0;
                break;
            }
        }
    }
    //반환
    return answer;
}