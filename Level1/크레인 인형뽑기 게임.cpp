#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;

    //�̵� ��� �ϳ��� Ȯ��
    for (int i = 0; i < moves.size(); ++i) {
        int idx = moves[i] - 1;
        for (int j = 0; j<board.size();++j) {
            if (board[j][idx] != 0) {

                //������� �ʰ� ������ ������ �ٱ��� ����� ������ ���ٸ�
                if (!basket.empty() && basket.top() == board[j][idx]) {
                    basket.pop();
                    //����
                    answer += 2;
                }
                //����
                else
                    basket.push(board[j][idx]);

                board[j][idx] = 0;
                break;
            }
        }
    }
    //��ȯ
    return answer;
}