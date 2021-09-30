#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    //먼저 갈+노로 시작
    int width = brown + yellow;
    //절반으로 비교
    for (int i = width / 2; i > 0; i--) {
        //나누어 떨어진다면
        if (width % i == 0) {
            int row = i;
            int col = width / i;
            //-2
            if ((row-2)*(col-2) == yellow) {
                answer.push_back(row);
                answer.push_back(col);
                break;
            }
        }
    }
    return answer;
}
