#include <string>
#include <vector>

using namespace std;

int cnt = 0;
vector<int> mash(2, 0); //망
vector<int> adj[101]; //인접리스트
vector<int> visited; //방문리스트

//반환
int Min(int a, int b) {
    return a < b ? a : b;
}

//반환
int Abs(int a) {
    return a < 0 ? -a : a;
}

//깊이우선탐색
void DFS(int n, int cur, int y, int x) {
    visited[cur] = 1;
    mash[cnt]++;

    for (int& next : adj[cur]) {
        //둘로 나누는 지점인지 체크
        if ((next == y && cur == x) || (next == x && cur == y))
            continue;

        //재방문
        if (visited[next] == 1)
            continue;

        DFS(n, next, y, x);
    }
    return;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 0x7fffffff; //최솟값을 위한
    int size = wires.size();

    //인접리스트 생성
    for (int i = 0; i < size; i++) {
        adj[wires[i][0]].push_back(wires[i][1]);
        adj[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 0; i < size; ++i) {
        visited = vector<int>(n + 1, 0); //방문리스트 초기화
        int y = wires[i][0];
        int x = wires[i][1];

        for (int j = 1; j <= n; ++j) {
            //재방문인 경우
            if (visited[j] == 1)
                continue;
            //호출
            DFS(n, j, y, x);
            cnt++;
        }

        //둘로 나눠졌다면
        if (cnt == 2)
            answer = Min(answer, Abs(mash[0]-mash[1]));

        cnt = 0; //횟수 초기화
        mash = vector<int> (2, 0); //망 벡터 초기화
    }

    return answer;
}