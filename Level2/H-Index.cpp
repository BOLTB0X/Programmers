#include <string>
#include <vector>

using namespace std;

//������ �Լ� ���� ��ġ ���� ����
void swap(int* a, int* b) {
    int *tmp = a;
    a = b;
    b = tmp;
    return;
}

//������
void quicksort(vector<int> &arr, int start, int end) {
    //���� ���Ұ� �ϳ����
    if (start >= end) 
        return;
    
    //�ǹ��� ù��° ����
    int pivot = start;
    int left = start + 1;
    int right = end;
    
    //�¿찡 ������������ �ݺ�
    while (left<=right) {
        //�ǹ����� ū �����͸� ã�� ������ �ݺ�
        while (left <= end && arr[left] <= arr[pivot])
            left++;
        //�ǹ����� ���� �����͸� ã�� ������ �ݺ�
        while (right > start && arr[right] >= arr[pivot])
            right--;
        //���� �����ȴٸ�
        if (left > right)
            swap(arr[pivot], arr[right]);
        else
            swap(arr[left], arr[right]);
    }
    //���� ���� ���� �κа� ������ �κп��� ���� ����
    quicksort(arr, start, right - 1);
    quicksort(arr, right + 1, end);
}

int solution(vector<int> citations) {
    int answer = 0;
    //������ �̿� ��������
    quicksort(citations, 0, citations.size() - 1);
    //������ ���̸� �ƴ� 1���� n���� ����Ž��
    for (int i = 0; i < citations.size(); i++) {
        //h-index ����
        //�� ���ʹ� ���� Ŀ���� h-idx�� �۾���
        int h_idx = citations.size() - i;

        if (citations[i] >= h_idx) {
            //ã�Ƹ�
            answer = h_idx;
            break;
        }
    }
    return answer;
}