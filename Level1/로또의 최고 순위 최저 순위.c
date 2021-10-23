#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//스와핑
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;

	return;
}

//퀵 정렬
void quick_sort(int *a, int start, int end) {
	//탈출 조건
	if (start >= end) 
		return;
	//i는 왼쪽 j는 오른쪽, 피벗 값을 가장 왼쪽으로 가정
	int pivot = start, left = start + 1, right = end;
	
	//엇갈리기 전까지 반복
	while (left <= right) { 
		//피벗보다 큰 값이 i에 담긴다.
		while (left <= end && a[left] <= a[pivot]) 
			left++; 
		//피벗보다 작은 값이 j에 담기도록
		while (right > start && a[right] >= a[pivot]) 
			right--; 
		//엇갈렷을 경우
		if (left > right) 
			swap(&a[pivot], &a[right]);
		else 
			swap(&a[left], &a[right]);
	}
	// 엇갈릴 때 부분적 재귀적으로 호출
	quick_sort(a, start, right - 1);
	quick_sort(a, right + 1, end);
}

//지워진 갯수 확인
int get_remove_number_count(int* a, int len) {
	int r_cnt = 0;
	for (int i = 0; i < len; ++i) {
		//지워진 갯수 발견
		if (a[i] == 0)
			r_cnt++;
	}

	return r_cnt;
}

//등수 반환 함수
int get_rank(int n) {
	//각 경우의 수가 몇 위에 해당하는 지 확인

	//1등인 경우
	if (n == 6)
		return 1;
	//2등인 경우
	else if (n == 5)
		return 2;
	//3등인 경우
	else if (n == 4)
		return 3;
	//4등인 경우
	else if (n == 3)
		return 4;
	//5등인 경우
	else if (n == 2)
		return 5;
	//6등인 경우
	else
		return 6;
}

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    //정답 배열
    int* answer = (int*)malloc(2);
    //중복 방지용 체크리스트
    bool visited[6] = { false, };
	//최악의 경우
	int min_cnt = 0;

	//오름차순 정렬
	quick_sort(lottos, 0, lottos_len - 1);

	//로또 번호와 당첨 번호들이 얼마나 맞는지 확인
	for (int i = 0; i < lottos_len; ++i) {
		for (int j = 0; j < win_nums_len; ++j) {
			//맞을 경우
			if (!visited[i] && lottos[i] == win_nums[j]) {
				min_cnt++;
				//중복 방지
				visited[i] = true;
			}
		}
	}

	//가장 좋은 경우
	//확인 할수 있는 당첨번호 + 지워진 수
	int max_cnt = min_cnt + get_remove_number_count(lottos, lottos_len);
	
	//각 횟수에 해당하는 등수를 반환	
	answer[0] = get_rank(max_cnt);
	answer[1] = get_rank(min_cnt);

    return answer;
}