#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int dp[100000][4] = { 0, };
    int row_len = land.size();
    
    //dp 2차원 배열의 첫번재 행에 셋팅 값 삽입
    for (int i = 0; i < 4; i++) 
        dp[0][i] = land[0][i];
    
    for (int i = 1; i < row_len; i++) {
        //가장 큰 값을 알기위한 임시값
        for (int j = 0; j < 4; j++) {
            int tmp_max = 0; //땅따먹기 문제 조건
            for (int k = 0; k < 4; k++) {
                if (j == k) 
                    continue; //같은 열 이동 불가능
                tmp_max = max(tmp_max, dp[i-1][k]);
            }
            //타겟에 최대값을 넣어줌
            dp[i][j] = land[i][j] + tmp_max;
        }
    }
    answer = max(dp[row_len - 1][0], max(dp[row_len - 1][1], max(dp[row_len - 1][2], dp[row_len - 1][3])));
    return answer;
}