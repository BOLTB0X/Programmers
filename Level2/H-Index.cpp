#include <string>
#include <vector>

using namespace std;

void swap(int *a, int *b) {
    int *tmp=a;
    a=b;
    b=tmp;
    return;
}

//퀵정렬
void quicksort(vector<int> &arr, int start, int end) {
    //만약 원소가 하나라면
    if (start>=end)
        return;
    int pivot=start;
    int left=pivot+1;
    int right=end;
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
    quicksort(arr,start,right-1);
    quicksort(arr,right+1,end);
    return;
}

int solution(vector<int> citations) {
    int answer = 0;
    //퀵 정렬을 이용한 오름차순 정렬
    quicksort(citations,0,citations.size()-1);
    //정렬된 벡터에서 길이와 그 인텍스를 뺀 값이 원소보다 크면 그 값이
    //h_index
    for (int i=0;i<citations.size();i++) {
        //즉 깊이 들어갈 수록 h_idx값은 줄어든다.
        int h_idx=citations.size()-i;
        if (citations[i] >= h_idx) {
            answer=h_idx;
            break; //안그럼 계속 진행됨
        }
    }
    return answer;
}
