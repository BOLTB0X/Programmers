#include <string>
#include <vector>

using namespace std;

//깊이 우선 탐색
void DFS(vector<vector<int>> &computers, vector<bool> &visited,int start) {
    visited[start]=true;
    //행 길이와 열 길이가 같으므로
    //인접행렬
    for (int i=0;i<computers.size();++i) {
        //재방문인 경우
        if (visited[i])
            continue;
        
        //연결되어있지 않을 경우
        if (computers[start][i] == 0)
            continue;
        
        //다음 정점으로 DFS
        DFS(computers,visited,i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    //방문리스트 생성 및 초기화
    vector<bool> visited(n,false);
    
    //각 컴퓨터들의 연결요소를 나타내는 정점 탐색
    for (int i=0;i<computers.size();++i) {
        //미방문이면
        if(!visited[i]) {
            //카운트
            answer++;
            //DFS호출
            DFS(computers,visited,i);
        }
    }
    return answer;
}
