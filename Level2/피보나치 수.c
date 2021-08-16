#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int dp[100001] = { 0, };
    for (int i = 1; i <= n; i++) {
        if (i < 2) {
            dp[i] = 1;
        }
        else {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
        }
    }
    answer = dp[n];
    return answer;
}