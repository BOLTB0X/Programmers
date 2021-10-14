#include <string>
#include <vector>

using namespace std;

//dp 2���� �迭
int dp[101][101] = { 0, };

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
   
    //���� �� 1�� ����
    dp[1][1] = 1;

    //���� ��� ������ �ǳ� �� ����
    //-1���� ��ü
    for (int i = 0; i < puddles.size(); ++i)
        //�� �� ����
        dp[puddles[i][1]][puddles[i][0]] = -1;

    //���� �ùķ��̼� ����ó�� 2�� for������ ����
    //�����ʰ� �Ʒ������θ� ������ ������ �б����� �� �� �ִ� �ִܰ���� ����
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            int up = 0;
            int right = 0;
            //�� �������� ���
            if (dp[y][x] == -1)
                continue;
            //�� �����̰� �ƴϸ�
            if (dp[y - 1][x] != -1)
                //�̵� �Ÿ� ����
                up = dp[y - 1][x];
            if (dp[y][x - 1] != -1)
                //�̵� �Ÿ� ����
                right = dp[y][x - 1];
            dp[y][x] += (up + right) % 1000000007;
        }
    }
    answer = dp[n][m];
    return answer;
}