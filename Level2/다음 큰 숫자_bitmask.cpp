#include <string>
#include <vector>
using namespace std;

string get_binary(int number) {
	string ret = "";

	while (number >= 1) {
		ret += to_string(number % 2);
		number /= 2;
	}
	return ret;
}

int get_one_cnt(string s) {
	int one_cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') one_cnt += 1;
	}
	return one_cnt;
}

int solution(int n) {
	int answer = 0;
	int idx = 1;
	int flag = get_one_cnt(get_binary(n));

	while (true) {
		if (flag == get_one_cnt(get_binary(n + idx))) {
			answer = n + idx;
			break;
		}
		idx++;
	}
	return answer;
}