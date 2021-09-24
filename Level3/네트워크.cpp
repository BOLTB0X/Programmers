#include <string>
#include <vector>

using namespace std;

//DFS로 그래프 탐색
void DFS(int start, int n, vector<vector<int>> &computers, vector<bool> &visited) {
    visited[start]=true;
    for (int i=0;i<computers[start].size();i++) {
        //미방문이고 1인 경우
        if(!visited[i] && computers[start][i] == 1) 
            DFS(i,n,computers,visited);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    //방문 벡터 초기화
    vector<bool> visited(n,false);
    //정점갯수만큼 돌림
    for (int i=0;i<n;i++) {
        //미방문일시
        if (!visited[i]) {
            //네트워크 카운트 이제 이에 연결된 노드를은 DFS로 처리
            answer++;
            DFS(i,n,computers,visited);
        }
    }
    return answer;
}
