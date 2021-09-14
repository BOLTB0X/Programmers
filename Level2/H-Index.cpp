#include <string>
#include <vector>

using namespace std;

//스와핑 함수 원소 위치 서로 변경
void swap(int* a, int* b) {
    int *tmp = a;
    a = b;
    b = tmp;
    return;
}

//퀵정렬
void quicksort(vector<int> &arr, int start, int end) {
    //만약 원소가 하나라면
    if (start >= end) 
        return;
    
    //피벗은 첫번째 원소
    int pivot = start;
    int left = start + 1;
    int right = end;
    
    //좌우가 엇갈릴때까지 반복
    while (left<=right) {
        //피벗보다 큰 데이터를 찾을 때까지 반복
        while (left <= end && arr[left] <= arr[pivot])
            left++;
        //피벗보다 작은 데이터를 찾을 때까지 반복
        while (right > start && arr[right] >= arr[pivot])
            right--;
        //만약 엇갈렸다면
        if (left > right)
            swap(arr[pivot], arr[right]);
        else
            swap(arr[left], arr[right]);
    }
    //분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬
    quicksort(arr, start, right - 1);
    quicksort(arr, right + 1, end);
}

int solution(vector<int> citations) {
    int answer = 0;
    //퀵정렬 이용 오름차순
    quicksort(citations, 0, citations.size() - 1);
    //벡터의 길이를 아닌 1부터 n까지 완전탐색
    for (int i = 0; i < citations.size(); i++) {
        //h-index 지정
        //비교 벡터는 점점 커지고 h-idx는 작아짐
        int h_idx = citations.size() - i;

        if (citations[i] >= h_idx) {
            //찾아면
            answer = h_idx;
            break;
        }
    }
    return answer;
}