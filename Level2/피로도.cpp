#include <string>
#include <vector>

using namespace std;

int result = 0;
int len;
vector<int> need;
vector<int> used;
vector<bool> visited;

int max(int a, int b) {
    return a > b ? a : b;
}

void DFS(int cur, int level) {
    for (int i = 0; i < len; ++i) {
        //재방문
        if (visited[i])
            continue;
        //현재 피로도보다 필요 피로도가 크다면
        if (need[i] > cur)
            continue;
        visited[i] = true;
        DFS(cur - used[i], level + 1);
        visited[i] = false;
    }

    result = max(result, level);
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    len = dungeons.size();
    visited.resize(len, false);

    //필요, 소모 피로도 벡터의 삽입
    for (int i = 0; i < len; ++i) {
        need.push_back(dungeons[i][0]);
        used.push_back(dungeons[i][1]);
    }

    //호출
    DFS(k, 0);
    answer = result;
    return answer;
}