#include <string>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
    int* tmp = a;
    a = b;
    b = tmp;
}

//선택정렬 이용
void sort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min_idx = i; //최소값 설정
        for (int j = i; j < arr.size(); j++) {
            // 더 작은 값을 찾는다면
            if (arr[j] < arr[min_idx])
                min_idx = j; //교체
        }
        swap(arr[min_idx], arr[i]);
    }
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        vector<int> tmp;
        for (int j = 0; j < 3; j++) {
            tmp.push_back(commands[i][j]);
        }
        int start = tmp[0];
        int end = tmp[1];
        int target = tmp[2];
        tmp.clear();
        for (int k = start - 1; k < end; k++) {
            tmp.push_back(array[k]);
        }
        sort(tmp);
        answer.push_back(tmp[target - 1]);
    }
    return answer;
}