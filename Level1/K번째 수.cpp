#include <string>
#include <vector>

using namespace std;

//스와핑
void swap(int *a, int *b) {
    int *tmp=a;
    a=b;
    b=tmp;
}

//퀵정렬
void quicksort(vector<int> &arr, int start, int end) {
    //원소가 한개인 경우
    if (start >= end)
        return;
    int pivot=start;
    int left = start+1;
    int right =end;
    
    while (left <= right) {
        //피벗값보다 작은 값
        while (left <= end && arr[left] <= arr[pivot])
            left++;
        //피벗값보다 큰 값
        while (right > start && arr[right] >= arr[pivot])
            right--;
        //엇갈렸다면
        if (left > right)
            swap(arr[pivot],arr[right]);
        else
            swap(arr[left],arr[right]);
    }
    quicksort(arr,start,right-1);
    quicksort(arr,right+1,end);
    return;
}

//배열 슬라이딩
int sliding(vector<int> &array, int start, int end, int target) {
    vector<int> v;
    //벡터에 슬라이딩 된 원소들 삽입
    for (int i=start-1; i<end;i++) 
        v.push_back(array[i]);
    //정렬
    quicksort(v,0,v.size()-1);
    return v[target-1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    //먼저 커맨드의 요청에 따라 배열을 잘라야함
    //임시벡터 생성 후 임시벡터에 삽입
    for (int i=0;i<commands.size();i++) {
        //열은 3으로 고정
        //배열 슬라이딩 호출
        int ret = sliding(array,commands[i][0],commands[i][1],commands[i][2]);
        answer.push_back(ret);
    }
    return answer;
}
