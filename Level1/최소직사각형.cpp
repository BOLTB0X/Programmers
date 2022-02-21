#include <string>
#include <vector>

using namespace std;

//�ִ� ��ȯ
int MAX(int a, int b) {
    return a > b ? a : b;
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_row = -1, max_col = -1;

    //����
    int len = sizes.size();
    for (int i = 0; i < len; ++i) {
        if (sizes[i][0] < sizes[i][1]) {
            max_row = MAX(max_row, sizes[i][1]);
            max_col = MAX(max_col, sizes[i][0]);
        }
        else {
            max_row = MAX(max_row, sizes[i][0]);
            max_col = MAX(max_col, sizes[i][1]);
        }
    }
    answer = max_row * max_col; // ��ȯ
    return answer;
}