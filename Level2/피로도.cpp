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
        //��湮
        if (visited[i])
            continue;
        //���� �Ƿε����� �ʿ� �Ƿε��� ũ�ٸ�
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

    //�ʿ�, �Ҹ� �Ƿε� ������ ����
    for (int i = 0; i < len; ++i) {
        need.push_back(dungeons[i][0]);
        used.push_back(dungeons[i][1]);
    }

    //ȣ��
    DFS(k, 0);
    answer = result;
    return answer;
}