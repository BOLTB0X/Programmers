#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int soultion(int N, int number) {
	int answer = 0;

	//������ �ʿ䵵 ���� �ߺ��� �����ؾ��ϹǷ�
	unordered_set<int> dp[8];

	int tot = 0;
	//�� N, NN, NNN... dp �־���
	for (int i = 0; i < 8; ++i) {
		tot = 10 * tot + N;
		//�� N�� ������ ����
		dp[i].insert(tot);
	}

	//���� Ž��
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < i; ++j) {
			//�� n�� ������ �� �͵�� ����
			for (int a1 : dp[j]) {
				for (int a2 : dp[i - j - 1]) {
					dp[i].insert(a1 + a2);
					dp[i].insert(a1 - a2);
					dp[i].insert(a1 * a2);
					//0�� �� ������ �ȵǹǷ�
					if (a2 != 0)
						dp[i].insert(a1 / a2);
				}
			}
		}
	}

	//dp�ȿ� number�� ������� üũ
	for (int i = 0; i < 8; ++i) {
		if (dp[i].find(number) != dp[i].end()) {
			answer = i + 1;
			break;
		}
	}
	
	//���� ��ȯ
	return answer;
}