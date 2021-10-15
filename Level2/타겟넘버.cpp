#include <vector>

using namespace std;

//DFS를 사용하기 때문에 전역 result
int result=0;

//깊이 우선 탐색을 이용한 백트래킹
void DFS(vector<int> &numbers, int target, int tot, int depth) {
    //numbers벡터까지 도달한다면 
    if (depth == numbers.size()) {
        //target으로 만들 수 있다면
        if (tot == target)
            result++;
        return;
    }
    //각각 덧셈 뺄셈한 것들로 DFS호출
    DFS(numbers,target,tot+numbers[depth],depth+1);
    DFS(numbers,target,tot-numbers[depth],depth+1);
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    //DFS로 탐색 시작
    DFS(numbers,target,0,0);
    answer=result;
    
    //정답 반환
    return answer;
}
