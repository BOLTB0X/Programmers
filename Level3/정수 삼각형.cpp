#include <string>
#include <vector>

using namespace std;

//최대
int max(int a, int b) {
    return a>b?a:b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    //길이
    int size = triangle.size();
    //dp 2차원 배열 동적할당 생성 
    int **dp;
    dp = new int*[size+1];
    for (int i=0;i<=size;++i) 
        dp[i] = new int [size+1];
    
    //초기화
    for (int i=0;i<=size;++i) {
        for (int j=0;j<=size;++j) {
            dp[i][j]=0;
        }
    }
    
    //최상단 값 셋팅
    dp[1][1]=triangle[0][0];
    //정수 삼각형을 위에서 아래로 떨어지는 방식으로 진행
    //즉 최하단에 더한 최댓값들이 있게 진행해야함
    //보텀업 방식
    for (int i=2;i<=triangle.size();++i) {
        //행의 idx 크기만큼 열이 존재 하므로 
        for (int j=1; j<=i;++j) {
            //그 해당 행의 열 원소들을 차례로 큰 값을 찾고
            //기존 정수삼각형 값을 더해줌
            dp[i][j]= max(dp[i-1][j-1],dp[i-1][j])+triangle[i-1][j-1];
        }
    }
    
    //최댓값 찾기
    int max_value =dp[size][1];
    //최하단 탐색
    for (int i=1;i<=size;++i) {
        int tmp_value = dp[size][i];
        //큰 값을 발견하면
        if (tmp_value > max_value)
            max_value = tmp_value;
    }
    //정답 교체
    answer = max_value;
    
    //메모리 해제
    for (int i = 0; i <= size; ++i)
        delete[] dp[i];
    delete[] dp;
    
    //정답 반환
    return answer;
}
