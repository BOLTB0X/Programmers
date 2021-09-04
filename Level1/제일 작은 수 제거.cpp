#include <string>
#include <vector>

using namespace std;

int find_minidx(vector<int> v) {
    int min_idx = 0;
    for (int i = 1; i < v.size(); i++) {
        //더 작은 값을 발견하면
        if (v[i] < v[min_idx])
            min_idx = i;
    }
    return min_idx;
}

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() == 1) {
        answer.push_back(-1);
        return answer;
    }
    int min_idx = find_minidx(arr);
    for (int i = 0; i < arr.size(); i++) {
        if (min_idx == i)
            continue;
        answer.push_back(arr[i]);
    }
    return answer;
}