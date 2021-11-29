#include <string>
#include <vector>

using namespace std;

//상하좌우
const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

//체크용
bool flag;

//깊이우선탐색
void DFS(vector<string>& place, vector<vector<bool>>& visited, int y, int x, int depth) {
    //순차적으로 탐색
    for (int dir = 0; dir < 4; ++dir) {
        //길이가 2이던가 참이면
        if (depth == 2 || flag)
            return;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        //범위 내
        if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5) {
            //진행
            if (!visited[ny][nx] && place[ny][nx] != 'X') {
                //자리면
                if (place[ny][nx] == 'P') {
                    flag = true;
                    return;
                }
                else {
                    visited[ny][nx] = true;
                    DFS(place, visited, ny, nx, depth + 1);
                }
            }
        }
    }
    return;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    //각 대기실 
    for (auto& place : places) {
        //방문리스트 생성 및 초기화
        vector<vector<bool>> visited(5, vector<bool>(5, false));
        flag = false;
        //각 대기실 칸을 확인
        for (int i = 0; i < place.size(); ++i) {
            for (int j = 0; j < place[i].size(); ++j) {
                //미방문이고 좌석을 발견하면
                if (!visited[i][j] && place[i][j] == 'P') {
                    visited[i][j] = true;
                    DFS(place, visited, i, j, 0);
                }
                //거리두기를 지키지 않았으므로
                if (flag) {
                    answer.push_back(0);
                    break;
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            answer.push_back(1);
    }
    
    //반환
    return answer;
}