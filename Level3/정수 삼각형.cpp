#include <string>
#include <vector>

using namespace std;

//최댓값 반환
int MAX(int a, int b) {
    return a > b ? a : b;
}

vector<vector<int>> dp;
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size(); //길이
    dp.resize(size + 1, vector<int> (size + 1, 0)); //dp 초기화
    
    dp[1][1] = triangle[0][0];
    int max_value = dp[1][1];
    
    //보텀업방식
    for (int i = 2; i <= size; ++i) {
        //파스칼 규칙에 따라
        for (int j = 1; j<=i; ++j) {
            dp[i][j] = MAX(dp[i-1][j-1], dp[i-1][j]) + triangle[i - 1][j - 1];
            
            //최댓값 교체
            if (dp[i][j] > max_value)
                max_value = dp[i][j];
        }
    }
    
    answer = max_value; //최댓값
    return answer;
}
