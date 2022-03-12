#include <string>
#include <vector>

using namespace std;

int cnt = 0;
vector<int> mash(2, 0); //��
vector<int> adj[101]; //��������Ʈ
vector<int> visited; //�湮����Ʈ

//��ȯ
int Min(int a, int b) {
    return a < b ? a : b;
}

//��ȯ
int Abs(int a) {
    return a < 0 ? -a : a;
}

//���̿켱Ž��
void DFS(int n, int cur, int y, int x) {
    visited[cur] = 1;
    mash[cnt]++;

    for (int& next : adj[cur]) {
        //�ѷ� ������ �������� üũ
        if ((next == y && cur == x) || (next == x && cur == y))
            continue;

        //��湮
        if (visited[next] == 1)
            continue;

        DFS(n, next, y, x);
    }
    return;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 0x7fffffff; //�ּڰ��� ����
    int size = wires.size();

    //��������Ʈ ����
    for (int i = 0; i < size; i++) {
        adj[wires[i][0]].push_back(wires[i][1]);
        adj[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 0; i < size; ++i) {
        visited = vector<int>(n + 1, 0); //�湮����Ʈ �ʱ�ȭ
        int y = wires[i][0];
        int x = wires[i][1];

        for (int j = 1; j <= n; ++j) {
            //��湮�� ���
            if (visited[j] == 1)
                continue;
            //ȣ��
            DFS(n, j, y, x);
            cnt++;
        }

        //�ѷ� �������ٸ�
        if (cnt == 2)
            answer = Min(answer, Abs(mash[0]-mash[1]));

        cnt = 0; //Ƚ�� �ʱ�ȭ
        mash = vector<int> (2, 0); //�� ���� �ʱ�ȭ
    }

    return answer;
}