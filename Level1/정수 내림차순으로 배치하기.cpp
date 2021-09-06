#include <string>
#include <vector>

using namespace std;

void quickSort(vector<int>& arr, int start, int end) {
	if (start >= end) return; //���Ұ� 1���� ���
	int pivot = start; //�ǹ��� ù ��° ����
	int left = start + 1;
	int right = end;
	while (left <= right) {
		//�ǹ����� ū �����͸� ã�� ������ �ݺ�
		while (left <= end && arr[left] >= arr[pivot]) left++;
		// �ǹ����� ���� �����͸� ã�� ������ �ݺ�
		while (right > start && arr[right] <= arr[pivot]) right--;
		// �����ȴٸ� ���� �����Ϳ� �ǹ��� ��ü
		if (left > right) swap(arr[pivot], arr[right]);
		// �������� �ʾҴٸ� ���� �����Ϳ� ū �����͸� ��ü
		else swap(arr[left], arr[right]);
	}
	// ���� ���� ���� �κа� ������ �κп��� ���� ���� ����
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