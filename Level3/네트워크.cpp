#include <string>
#include <vector>

using namespace std;

void DFS(int start, int n, vector<vector<int>>& computers, vector<bool>& visited) {
    visited[start] = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && computers[start][i] != 0) {
            DFS(i, n, computers, visited);
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            DFS(i, n, computers, visited);
        }
    }
    return answer;
}