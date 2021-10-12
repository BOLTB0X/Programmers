#include <string>
#include <vector>

using namespace std;

//최대
int max(int a, int b) {
    return a > b ? a : b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    //동적할당 시작
    int** dp;
    int size = triangle.size();

    //동적할당
    dp = new int* [size + 1];
    for (int i = 0; i <= size; ++i) {
        dp[i] = new int[size + 1];
    }
    //초기화
    for (int i = 0; i <= size; ++i) {
        for (int j = 0; j <= size; ++j) {
            dp[i][j] = 0;
        }
    }
    //최상단 셋팅
    dp[1][1] = triangle[0][0];

    //보텀업
    for (int r = 2; r <= size; ++r) {
        for (int c = 1; c <= r; ++c) {
            dp[r][c] = max(dp[r - 1][c - 1], dp[r - 1][c]) + triangle[r - 1][c - 1];
        }
    }

    //최댓값 찾기
    //최하단
    int max_value = dp[size][1];
    //탐색하며 최댓값을 찾을 경우 교체
    for (int i = 2; i <= size; ++i) {
        if (dp[size][i] > max_value)
            max_value = dp[size][i];
    }
    answer = max_value;

    //메모리 해제
    for (int i = 0; i <= size; ++i)
        delete[] dp[i];
    delete[] dp;
    return answer;
}
