#include <string>
#include <vector>

using namespace std;

long long answer = 0;
vector<long long> adj[300001]; //��������Ʈ�� ����

long long Abs(long long a) {
    return a < 0 ? -a : a;
}

void DFS(vector<long long>& tot, int cur, int par) {
    for (long long& next : adj[cur]) {
        if (next != par) //�θ���� �ٸ��ٸ�
            DFS(tot, next, cur);
    }
    // DFS �� Ž�� ����
    tot[par] += tot[cur];
    answer += Abs(tot[cur]);

    return;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long size = a.size();
    vector<long long> tot(size, 0); //long long
    for (long long i = 0; i < size; ++i)
        tot[i] = a[i];

    for (int i = 0; i < edges.size(); ++i) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    DFS(tot, 0, 0); //���̿켱Ž��

    if (tot[0] == 0)
        return answer;
    return -1;
}