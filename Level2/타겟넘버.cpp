#include <vector>

using namespace std;
//답
int answer = 0;

void DFS(vector<int> &arr,int tot, int target, int idx) {
    //탈출 조건
    //기존 벡터의 길이까지 반복하면
    if (idx == arr.size()) {
        //총합이 타겟과 같다면
        if (tot == target)
            answer++;
        return;
    }
    DFS(arr, tot + arr[idx], target, idx + 1);
    DFS(arr, tot - arr[idx], target, idx + 1);
}

int solution(vector<int> numbers, int target) {
    //DFS 탐색 시작
    DFS(numbers,0, target, 0);
    return answer;
}
