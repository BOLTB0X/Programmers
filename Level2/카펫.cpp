#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width = brown + yellow;
    for (int i = width / 2; i > 0; i--) {
        if (width % i == 0) {
            int row = i;
            int col = width / i;
            if ((row-2)*(col-2) == yellow) {
                answer.push_back(row);
                answer.push_back(col);
                break;
            }
        }
    }
    return answer;
}