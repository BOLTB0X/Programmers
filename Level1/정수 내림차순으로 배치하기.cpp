#include <string>
#include <vector>

using namespace std;

void quickSort(vector<int>& arr, int start, int end) {
	if (start >= end) return; //원소가 1개인 경우
	int pivot = start; //피벗은 첫 번째 원소
	int left = start + 1;
	int right = end;
	while (left <= right) {
		//피벗보다 큰 데이터를 찾을 때까지 반복
		while (left <= end && arr[left] >= arr[pivot]) left++;
		// 피벗보다 작은 데이터를 찾을 때까지 반복
		while (right > start && arr[right] <= arr[pivot]) right--;
		// 엇갈렸다면 작은 데이터와 피벗을 교체
		if (left > right) swap(arr[pivot], arr[right]);
		// 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
		else swap(arr[left], arr[right]);
	}
	// 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
	quickSort(arr, start, right - 1);
	quickSort(arr, right + 1, end);
}

long long solution(long long n) {
	long long answer = 0;
	string tmp_s = to_string(n);
	string s = "";
	vector<int> tmp_v;
	for (int i = 0; i < tmp_s.length(); i++)
		tmp_v.push_back((int)tmp_s[i] - '0');
	quickSort(tmp_v, 0, tmp_v.size() - 1);
	for (int i = 0; i < tmp_v.size(); i++)
		s += (char)tmp_v[i] + '0';
	answer = stoll(s.c_str());
	return answer;
}