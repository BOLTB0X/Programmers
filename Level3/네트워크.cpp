#include <string>
#include <vector>

using namespace std;

//깊이 우선
void DFS(int start, int n, vector<vector<int>>& computers, vector<bool>& visited) {
    //방문체크
    visited[start] = true;
    //정점 갯수만큼 순회
    for (int i = 0; i < n; i++) {
        //재방문이면
        if (visited[i])
            continue;
        //연결되어있지 않다면
        if (computers[start][i] == 0)
            continue;
        //DFS 호출
        DFS(i, n, computers, visited);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    //체크리스트 초기화
    vector<bool> visited(n, false);
    //네트워크의 갯수는 각 정점을 for문으로 순회하여 
    //미방문 정점을 발견하여 DFS하는 갯수와 같다.
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            DFS(i, n, computers, visited);
        }
    }
    //정답 반환
    return answer;
}
