#include <string>
#include <vector>

using namespace std;

//퀵정렬
void quick_Sort(vector<int> &arr, int start, int end) {
    //원소가 한개인 경우
    if (start >= end)
        return;
    //피벗과 왼 오 셋팅
    int pivot = start;
    int left = start+1;
    int right = end;
    
    //엇갈릴때 까지 반복
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
    quick_Sort(arr,start,right-1);
    quick_Sort(arr,right+1,end);
    return;
}

//요구되로 원소 구하기
int vector_sliding(vector<int> &array, int start, int end, int target) {
    vector<int> tmp;
    for (int i = start - 1; i < end; ++i) {
        tmp.push_back(array[i]);
    }
    
    quick_Sort(tmp, 0, tmp.size() - 1); //정렬
    return tmp[target-1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    //명령대로 배열 원소 구함
    for (auto& cmd : commands) {
        int ret = vector_sliding(array, cmd[0],cmd[1], cmd[2]);
        answer.push_back(ret);
    }
    
    //반환
    return answer;
}
