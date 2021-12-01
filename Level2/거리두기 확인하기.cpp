#include <string>
#include <vector>

using namespace std;

//체크용
bool flag;

//상하좌우
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//깊이우선탐색
//2만 탐색하여 거리두기 되었는지 체크
void DFS(vector<string>& place, vector<vector<bool>>& visited, int y, int x, int depth) {
    //순차적으로 탐색
    for (int dir = 0; dir < 4; ++dir) {
        //탈출
        if (depth == 2 || !flag)
            return;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        //범위내
        if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5) {
            if (!visited[ny][nx] && place[ny][nx] != 'X') {
                //거리두기 실패
                if (place[ny][nx] == 'P') {
                    flag = false;
                    return;
                }
                else {
                    visited[ny][nx] = true;
                    //DFS호출
                    DFS(place, visited, ny, nx, depth + 1);
                }
            }
        }
    }
    return;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    //체크할 대기실
    for (auto& place : places) {
        //대기실이 바뀔때마다 방문리스트 초기화
        vector<vector<bool>> visited(5, vector<bool>(5, false));
        //거리두기를 지켰으면 참 아니면 거짓
        flag = true;
        //선택된 대기실 좌석들 확인
        for (int i = 0; i < place.size(); ++i) {
            for (int j = 0; j < place[i].size(); ++j) {
                //확인 안한 좌석을 발견한다면 
                if (place[i][j] == 'P' && !visited[i][j]) {
                    visited[i][j] = true;
                    DFS(place, visited, i, j, 0);
                }
                //DFS호출 후 거리두기를 안지켰다면
                if (!flag) {
                    answer.push_back(0);
                    break;
                }
            }
            //거리두기를 안지켰다면
            if (!flag)
                break;
        }
        //지켰다면
        if (flag)
            answer.push_back(1);
    }

    //반환
    return answer;
}
