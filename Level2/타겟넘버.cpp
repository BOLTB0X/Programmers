#include <string>
#include <vector>

using namespace std;

//전역변수로 카운트
int cnt = 0;

void DFS(vector<int>& numbers, int target, int level, int tot) {
    if (level == numbers.size()) {
        if (tot == target)
            cnt++;
        return;
    }
    DFS(numbers, target, level+1, tot + numbers[level]);
    DFS(numbers, target, level+1, tot - numbers[level]);
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(numbers,target,0,0);
    answer = cnt;
    
    return answer;
}
