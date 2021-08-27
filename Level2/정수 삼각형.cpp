#include <string>
#include <vector>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int dp[501][501] = { 0, };
    dp[1][1] = triangle[0][0];

    for (int r = 2; r <= triangle.size(); r++) {
        for (int c = 1; c <= r; c++) {
            dp[r][c] = max(dp[r-1][c-1], dp[r-1][c]) + triangle[r-1][c-1];
        }
    }
    int max_value = dp[triangle.size()][1];
    for (int i = 2; i <= triangle.size(); i++) {
        if (max_value < dp[triangle.size()][i])
            max_value = dp[triangle.size()][i];
    }
    answer = max_value;
    return answer;
}