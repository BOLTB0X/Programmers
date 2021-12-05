#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;

    //이동 명령 하나씩 확인
    for (int i = 0; i < moves.size(); ++i) {
        //열 결정
        int idx = moves[i] - 1;
        //격자판 탐섹
        for (auto& b : board) {
            //인형 발견
            if (b[idx] != 0) {
                //득점이 가능한 경우
                if (!basket.empty() && basket.top() == b[idx]) {
                    basket.pop();
                    answer += 2;
                }
                else
                    basket.push(b[idx]);
                //인형을 꺼냈으므로
                b[idx] = 0;
                break;
            }
        }
       
    }
    //반환
    return answer;
}
