#include <vector>

using namespace std;

//횟수 초기화
int cnt = 0;

void DFS(int tot, vector<int>& numbers, int target, int depth) {
    //깊이가 벡터길이까지 도달했다면 == 탈출조건
    if (depth == numbers.size()) {
        //총합이 타켓과 같다면
        if (tot == target) {
            //카운트
            cnt++;
        }
        return;
    }
    //더하거나 뺄경우를 DFS 호출
    DFS(tot + numbers[depth], numbers, target, depth + 1);
    DFS(tot - numbers[depth], numbers, target, depth + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    //백트래킹 기법으로 완전탐색
    DFS(0, numbers, target, 0);
    //카운팅된 cnt를 answer에 넣어줌
    answer = cnt;
    return answer;
}
