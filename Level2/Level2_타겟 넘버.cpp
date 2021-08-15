#include <string>
#include <vector>
using namespace std;

int cnt;
void DFS(vector<int> &numbers, int &target, int tot, int idx) {
    if (idx >= numbers.size()) {
        if (tot == target) 
            cnt += 1;
        return;
    }
    DFS(numbers, target, tot+numbers[idx], idx+1);
    DFS(numbers, target, tot-numbers[idx], idx+1);
}

int solution(vector<int> numbers, int target) {
    int answer=0;
    DFS(numbers, target, numbers[0], 1);
    DFS(numbers, target, -numbers[0], 1);
    answer = cnt;
    return answer;
}
