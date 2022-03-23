#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void DFS(vector<int>& numbers, int target, int level, int tot) {
    //탈출 조건
    if (level == numbers.size()) {
        if (tot == target) //조건 성립시
            cnt++;
        return;
    }
    
    DFS(numbers, target, level+1, tot + numbers[level]);
    DFS(numbers, target, level+1, tot - numbers[level]);
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    //탐색 시작
    DFS(numbers, target, 0,0);
    answer = cnt;
    
    return answer;
}
