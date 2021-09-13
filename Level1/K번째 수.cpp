#include <string>
#include <vector>

using namespace std;

//스와프
void swap(int *a, int *b) {
    int *tmp = a;
    a=b;
    b=tmp;
}

//퀵정렬 이용
void quicksort(vector<int>& arr, int start, int end) {
    if (start >= end)
        return;
    int pivot = start;
    int left = start+1;
    int right = end;
    while (left <= right) {
        //피벗보다 큰 데이터를 찾을 때까지 반복
		while (left <= end && arr[left] <= arr[pivot]) left++;
		// 피벗보다 작은 데이터를 찾을 때까지 반복
		while (right > start && arr[right] >= arr[pivot]) right--;
		// 엇갈렸다면 작은 데이터와 피벗을 교체
		if (left > right) swap(arr[pivot], arr[right]);
		// 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
		else swap(arr[left], arr[right]);
    }
    quicksort(arr,start,right-1);
    quicksort(arr,right+1,end);
}

// 배열자르기
int sliding_arr(vector<int> array,vector<int> tmp) {
    vector<int> result;
    int start=tmp[0];
    int end=tmp[1];
    int target=tmp[2];
    //문제 조건에 맞게 배열원소 삽입
    for (int i=start-1;i<end;i++) {
        result.push_back(array[i]);
    }
    //퀵정렬로 오름차순
    quicksort(result,0,result.size()-1);
    //타겟 원소 반환
    return result[target-1];
}

//해결
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    //명령 갯수만큼 일단 
    for (int i=0;i<commands.size();i++) {
        vector<int> tmp;
        for (int j=0; j<3; j++) {
            tmp.push_back(commands[i][j]);
        }
        //문제조건에 맞게
        int ret= sliding_arr(array,tmp);
        answer.push_back(ret);
    }
    return answer;
}
