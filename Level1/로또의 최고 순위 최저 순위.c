#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//������
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;

	return;
}

//�� ����
void quick_sort(int *a, int start, int end) {
	//Ż�� ����
	if (start >= end) 
		return;
	//i�� ���� j�� ������, �ǹ� ���� ���� �������� ����
	int pivot = start, left = start + 1, right = end;
	
	//�������� ������ �ݺ�
	while (left <= right) { 
		//�ǹ����� ū ���� i�� ����.
		while (left <= end && a[left] <= a[pivot]) 
			left++; 
		//�ǹ����� ���� ���� j�� ��⵵��
		while (right > start && a[right] >= a[pivot]) 
			right--; 
		//�������� ���
		if (left > right) 
			swap(&a[pivot], &a[right]);
		else 
			swap(&a[left], &a[right]);
	}
	// ������ �� �κ��� ��������� ȣ��
	quick_sort(a, start, right - 1);
	quick_sort(a, right + 1, end);
}

//������ ���� Ȯ��
int get_remove_number_count(int* a, int len) {
	int r_cnt = 0;
	for (int i = 0; i < len; ++i) {
		//������ ���� �߰�
		if (a[i] == 0)
			r_cnt++;
	}

	return r_cnt;
}

//��� ��ȯ �Լ�
int get_rank(int n) {
	//�� ����� ���� �� ���� �ش��ϴ� �� Ȯ��

	//1���� ���
	if (n == 6)
		return 1;
	//2���� ���
	else if (n == 5)
		return 2;
	//3���� ���
	else if (n == 4)
		return 3;
	//4���� ���
	else if (n == 3)
		return 4;
	//5���� ���
	else if (n == 2)
		return 5;
	//6���� ���
	else
		return 6;
}

// lottos_len�� �迭 lottos�� �����Դϴ�.
// win_nums_len�� �迭 win_nums�� �����Դϴ�.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    //���� �迭
    int* answer = (int*)malloc(2);
    //�ߺ� ������ üũ����Ʈ
    bool visited[6] = { false, };
	//�־��� ���
	int min_cnt = 0;

	//�������� ����
	quick_sort(lottos, 0, lottos_len - 1);

	//�ζ� ��ȣ�� ��÷ ��ȣ���� �󸶳� �´��� Ȯ��
	for (int i = 0; i < lottos_len; ++i) {
		for (int j = 0; j < win_nums_len; ++j) {
			//���� ���
			if (!visited[i] && lottos[i] == win_nums[j]) {
				min_cnt++;
				//�ߺ� ����
				visited[i] = true;
			}
		}
	}

	//���� ���� ���
	//Ȯ�� �Ҽ� �ִ� ��÷��ȣ + ������ ��
	int max_cnt = min_cnt + get_remove_number_count(lottos, lottos_len);
	
	//�� Ƚ���� �ش��ϴ� ����� ��ȯ	
	answer[0] = get_rank(max_cnt);
	answer[1] = get_rank(min_cnt);

    return answer;
}