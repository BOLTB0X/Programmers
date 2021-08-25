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
    
    //dp 2���� �迭�� ù���� �࿡ ���� �� ����
    for (int i = 0; i < 4; i++) 
        dp[0][i] = land[0][i];
    
    for (int i = 1; i < row_len; i++) {
        //���� ū ���� �˱����� �ӽð�
        for (int j = 0; j < 4; j++) {
            int tmp_max = 0; //�����Ա� ���� ����
            for (int k = 0; k < 4; k++) {
                if (j == k) 
                    continue; //���� �� �̵� �Ұ���
                tmp_max = max(tmp_max, dp[i-1][k]);
            }
            //Ÿ�ٿ� �ִ밪�� �־���
            dp[i][j] = land[i][j] + tmp_max;
        }
    }
    answer = max(dp[row_len - 1][0], max(dp[row_len - 1][1], max(dp[row_len - 1][2], dp[row_len - 1][3])));
    return answer;
}