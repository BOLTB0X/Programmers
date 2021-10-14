#include <string>
#include <vector>

using namespace std;

//최댓값 비교
int max(int a, int b) {
    return a>b?a:b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    //행의 길이
    int size = triangle.size();
    
    //메모이제이션을 위한 dp배열 생성 및 초기화
    int **dp;
    //생성
    dp = new int*[size+1];
    for (int i=0;i<=size;++i) {
        dp[i] = new int[size+1];
    }
    //초기화
    for (int i=0;i<=size;++i) {
        for (int j=0; j<=size;++j) {
            dp[i][j]=0;
        }
    }
  
    //최상단
    dp[1][1]=triangle[0][0];
    //최댓값 일단 셋팅
    int max_value=dp[1][1];
    
    //보텀업 방식으로 진행
    //상단에서 최하단으로 내려가며 마지막 행들을 최댓값들이 존재
    for (int i=2;i<=size;++i) {
        //열의 갯수는 그 행의 index
        for (int j=1;j<=i;++j) {
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+triangle[i-1][j-1];
            //최댓값보다 크다면
            if (dp[i][j] > max_value) 
                max_value=dp[i][j];
        }
    }
    //정답 
    answer=max_value;
    
    //메모리 해제
    for (int i=0;i<=size;++i)
        delete[] dp[i];
    delete[] dp;
    
    return answer;
}
