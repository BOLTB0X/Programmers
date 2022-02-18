#include <string>
#include <vector>

using namespace std;

//스와핑
void swap(int* a, int* b) {
    int* tmp = a;
    a = b;
    b = tmp;
    return;
}

//퀵정렬
void q_Sort(vector<int>& arr, int start, int end) {
    //원소가 1개일 경우
    if (start >= end)
        return;
    int pivot = start;
    int left = pivot + 1;
    int right = end;
    //탐색시작
    while (left <= right) {
        //피벗보다 큰값을 만날때까지 반복
        while (left <= end && arr[left] <= arr[pivot])
            left++;
        //피벗보다 작은 값을 만날때까지 반복
        while (right > start && arr[right] >= arr[pivot])
            right--;
        //엇갈렸다면
        if (left > right)
            swap(arr[right], arr[pivot]);
        else
            swap(arr[left], arr[right]);
    }
    q_Sort(arr, start, right - 1);
    q_Sort(arr, right + 1, end);
    return;
}

//원소에 있는지
bool is_Ele_in_arr(vector<int>& v, int target) {
    if (v.size() == 0)
        return true;
    
    int size = v.size();
    for (int i = 0; i < size; ++i) {
        if (target == v[i])
            return false;
    }
    
    return true;
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int size = numbers.size(), ele;
    bool flag;
    
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            ele = numbers[i] + numbers[j];
            flag = 1;
            if (!is_Ele_in_arr(answer, ele)) {
                flag = 0;
            }
            if (flag)
            answer.push_back(ele);
        }
        
    }
    
    q_Sort(answer, 0, answer.size() - 1);
    return answer;
}
