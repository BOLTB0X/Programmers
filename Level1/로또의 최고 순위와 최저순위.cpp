#include <string>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
    int* tmp = a;
    a = b;
    b = tmp;
}

void quicksort(vector<int>& arr, int start, int end) {
    if (start >= end) 
        return; //원소가 1개인 경우
    int pivot = start; //피벗은 첫 번째 원소
    int left = start + 1;
    int right = end;
    while (left <= right) {
        //피벗보다 큰 데이터를 찾을 때까지 반복
        while (left <= end && arr[left] <= arr[pivot]) 
            left++;
        // 피벗보다 작은 데이터를 찾을 때까지 반복
        while (right > start && arr[right] >= arr[pivot]) 
            right--;
        // 엇갈렸다면 작은 데이터와 피벗을 교체
        if (left > right) 
            swap(arr[pivot], arr[right]);
        // 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
        else 
            swap(arr[left], arr[right]);
    }
    // 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
    quicksort(arr, start, right - 1);
    quicksort(arr, right + 1, end);
}

//이진탐색 이용
bool is_target(vector<int>& arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (target == arr[mid])
            return true;
        else if (arr[mid] < target) 
            start = mid + 1;
        
        else
            end = mid - 1;
    }
    return false;
}

//0갯수 카운팅
int count_zero(vector<int>& arr) {
    int zero_cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0)
            zero_cnt++;
    }
    return zero_cnt;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    quicksort(win_nums, 0, win_nums.size() - 1);
    int min_cnt = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (is_target(win_nums, lottos[i], 0, win_nums.size() - 1))
            min_cnt++;
    }
    int max_cnt = min_cnt + count_zero(lottos);

    if (max_cnt == 6)
        answer.push_back(1);
    else if (max_cnt == 5)
        answer.push_back(2);
    else if (max_cnt == 4)
        answer.push_back(3);
    else if (max_cnt == 3)
        answer.push_back(4);
    else if (max_cnt == 2)
        answer.push_back(5);
    else if (max_cnt <= 1)
        answer.push_back(6);
    else if (max_cnt <= 1)
        answer.push_back(6);
    if (min_cnt == 6)
        answer.push_back(1);
    else if (min_cnt == 5)
        answer.push_back(2);
    else if (min_cnt == 4)
        answer.push_back(3);
    else if (min_cnt == 3)
        answer.push_back(4);
    else if (min_cnt == 2)
        answer.push_back(5);
    else if (min_cnt <= 1)
        answer.push_back(6);
    return answer;
}