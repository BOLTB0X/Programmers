#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int soultion(int N, int number) {
	int answer = 0;

	//정렬할 필요도 없고 중복값 제거해야하므로
	unordered_set<int> dp[8];

	int tot = 0;
	//각 N, NN, NNN... dp 넣어줌
	for (int i = 0; i < 8; ++i) {
		tot = 10 * tot + N;
		//즉 N의 갯수를 삽입
		dp[i].insert(tot);
	}

	//분할 탐색
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < i; ++j) {
			//각 n의 개수가 들어간 것들로 연산
			for (int a1 : dp[j]) {
				for (int a2 : dp[i - j - 1]) {
					dp[i].insert(a1 + a2);
					dp[i].insert(a1 - a2);
					dp[i].insert(a1 * a2);
					//0일 때 나누면 안되므로
					if (a2 != 0)
						dp[i].insert(a1 / a2);
				}
			}
		}
	}

	//dp안에 number가 들었는지 체크
	for (int i = 0; i < 8; ++i) {
		if (dp[i].find(number) != dp[i].end()) {
			answer = i + 1;
			break;
		}
	}
	
	//정답 반환
	return answer;
}