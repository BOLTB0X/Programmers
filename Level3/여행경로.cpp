#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//임시 정답
vector<string> tmp;

//깊이 우선 탐색
bool DFS(vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& answer, string cur_ticket, int depth) {
    //현재 티켓 정답 벡터에 삽입
    tmp.push_back(cur_ticket);

    //진행 깊이가 전체 티켓벡터의 길이까지 도달하면
    if (depth == tickets.size()) {
        answer = tmp;
        return true;
    }
    //현재 티켓을 행으로 탐색 시작
    for (int i = 0; i < tickets.size(); ++i) {
        //그 행의 첫 번째 열이 사용 티켓이고 미방문이면
        if (tickets[i][0] == cur_ticket && !visited[i]) {
            //방문 처리
            visited[i] = true;
            //다시 DFS로 탐색 시작
            bool is_success = DFS(tickets, visited, answer, tickets[i][1], depth + 1);
            //진행이 가능 하면 참으로 계속 진행
            //false면 중단시킴
            if (is_success)
                return true;
            visited[i] = false;
        }
    }
    //빼줌 안그러면 중복
    tmp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    //정답벡터
    vector<string> answer;

    //방문리스트 생성 및 초기화
    vector<bool> visited(tickets.size(), false);

    //알파벳 순서로 정렬
    sort(tickets.begin(), tickets.end());

    //다른 DFS랑 다르게 사용 티켓을 들고간다.
    //항상 "ICN" 공항에서 출발
    DFS(tickets, visited, answer, "ICN", 0);
    return answer;
}