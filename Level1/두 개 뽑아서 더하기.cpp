#include <string>
#include <vector>
#include <set>

using namespace std;

//������
void swap(int* a, int* b) {
    int* tmp = a;
    a = b;
    b = tmp;
    return;
}

//������
void quicksort(vector<int>& arr, int start, int end) {
    //���Ұ� 1���� ���
    if (start >= end)
        return;
    int pivot = start;
    int left = pivot + 1;
    int right = end;
    //Ž������
    while (left <= right) {
        //�ǹ����� ū���� ���������� �ݺ�
        while (left <= end && arr[left] <= arr[pivot])
            left++;
        //�ǹ����� ���� ���� ���������� �ݺ�
        while (right > start && arr[right] >= arr[pivot])
            right--;
        //�����ȴٸ�
        if (left > right)
            swap(arr[right], arr[pivot]);
        else
            swap(arr[left], arr[right]);
    }
    quicksort(arr, start, right - 1);
    quicksort(arr, right + 1, end);
    return;
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int tmp_value = numbers[i] + numbers[j];
            bool check = false;
            for (int k = 0; k < answer.size(); k++) {
                if (tmp_value == answer[k])
                    check = true;
            }
            if (!check)
                answer.push_back(tmp_value);
        }
    }
    quicksort(answer, 0, answer.size() - 1);
    return answer;
}