#include <string>
#include <vector>

using namespace std;

//퀵정렬
void quick_Sort(vector<int> &arr, int start, int end) {
    //만약 원소가 하나라면
    if (start >= end)
        return;
    int pivot = start;
    int left = pivot+1;
    int right = end;
    
    //엇갈리기 전까지
    while (left <= right) {
        //피벗보다 큰 값을 만날때 까지
        while (left <= end && arr[left] <= arr[pivot]) 
            left++;
        //피벗보다 작은 값을 만날 때 까지
        while (right > start && arr[right] >= arr[pivot])
            right--;
        //만약 엇갈렸다면
        if (left > right) 
            swap(arr[pivot],arr[right]);
        else
            swap(arr[left],arr[right]);
    }
    quick_Sort(arr, start, right-1);
    quick_Sort(arr, right+1, end);
    return;
}

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size(), h_idx = 0;
    
    quick_Sort(citations, 0, size - 1); //오름차순
    
    //정렬된 벡터에서 길이와 그 인텍스를 뺀 값이 원소보다 크면 그 값이
    //h_index
    for (int i = 0; i < size; ++i) {
        //즉 깊이 들어갈 수록 h_idx값은 줄어든다.
        h_idx = size - i;
        //H-idx를 알았으니
        if (citations[i] >= h_idx) {
            answer = h_idx;
            break; //안 멈추면 계속 작아짐
        }
    }
    return answer;
}
