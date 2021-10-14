#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//임시 벡터
vector<string> tmp;

//기존 DFS에서 처럼 해당 노드로 이동이 아닌
//다음 열로 탐사를 해야함
//그러므로 bool형 DFS사용
bool DFS(vector<vector<string>> &tickets, vector<bool> &visited, vector<string> &answer, string cur_ticket, int depth) {
    //현재 티켓 임시 벡터에 삽입
    tmp.push_back(cur_ticket);
    
    //전체 티켓들의 행 길이만큼 도달하면
    if (depth == tickets.size()) {
        answer = tmp;
        return true;
    }
    
    //현재 티켓 각 노드 탐색
    for (int i=0;i<tickets.size();++i) {
        //현재 티켓을 가진 행을 찾는다면
        //거기다 미방문
        if (tickets[i][0] == cur_ticket && !visited[i]) {
            //방문처리
            visited[i]=true;
            //다음 열로 DFS가 가능한지
            bool is_success = DFS(tickets,visited,answer,tickets[i][1],depth+1);
            
            //가능하면 진행
            if (is_success)
                return true;
            //모든 경우의 수를 탐사이므로
            visited[i]=false;
        }
    }
    //중복허용이 아니니
    tmp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    //정답벡터
    vector<string> answer;
    
    //방문벡터 생성 및 초기화
    vector<bool> visited(tickets.size(),false);
    
    //알파벳 순으로 방문이므로
    sort(tickets.begin(),tickets.end());
    
    //DFS로 공항 순회
    DFS(tickets,visited,answer,"ICN",0);
    
    return answer;
}
