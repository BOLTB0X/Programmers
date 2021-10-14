#include <string>
#include <vector>

using namespace std;

//dp 2차원 배열
int dp[101][101] = { 0, };

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
   
    //시작 점 1로 셋팅
    dp[1][1] = 1;

    //물에 잠긴 지역은 건널 수 없음
    //-1으로 교체
    for (int i = 0; i < puddles.size(); ++i)
        //행 열 조심
        dp[puddles[i][1]][puddles[i][0]] = -1;

    //보통 시뮬레이션 문제처럼 2중 for문으로 진행
    //오른쪽과 아래쪽으로만 움직여 집에서 학교까지 갈 수 있는 최단경로의 개수
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            int up = 0;
            int right = 0;
            //물 웅덩이인 경우
            if (dp[y][x] == -1)
                continue;
            //물 웅덩이가 아니면
            if (dp[y - 1][x] != -1)
                //이동 거리 저장
                up = dp[y - 1][x];
            if (dp[y][x - 1] != -1)
                //이동 거리 저장
                right = dp[y][x - 1];
            dp[y][x] += (up + right) % 1000000007;
        }
    }
    answer = dp[n][m];
    return answer;
}