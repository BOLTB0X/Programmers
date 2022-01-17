#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;

    //명령어 확인
    for (int i = 0; i < moves.size(); ++i) {
        int cmd = moves[i];
        
        //열로 이동
        for (int j = 0; j < board.size(); ++j) {
            if (board[j][cmd] != 0) {
                if (!st.empty() && st.top() == board[j][cmd])
                    answer += 2;
                else
                    st.push(board[j][cmd]);
                board[j][cmd] = 0;
                break;
            }
        }
    }

    return answer;
}
