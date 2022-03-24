#include <string>
#include <vector>

using namespace std;

typedef struct {
    int idx, dist;
} Node;

Node que[10001];
int fr = 0, re = 0;

void enqueue(Node data) {
    que[re++] = data;
    return;
}

Node dequeue(void) {
    return que[fr++];
}

vector<int> mash; //��
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

void BFS(int n, int start, int y, int x) {
    int max_dist = -1; //�ִ��� ����
    visited[start] = 1;
    fr = 0, re = 0; //ť �ʱ�ȭ
    enqueue({ start, 0 });

    while (fr < re) {
        Node cur = dequeue();

        for (int& next : adj[cur.idx]) {
            //��湮
            if (visited[next] == 1)
                continue;

            //���� ����
            if ((y == next && x == cur.idx) || (y == cur.idx && x == next))
                continue;

            int nd = cur.dist + 1;
            if (nd > max_dist)
                max_dist = nd;
            enqueue({ next, nd });
        }
    }

    mash.push_back(max_dist);
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
            BFS(n, j, y, x);
        }

        //�ѷ� �������ٸ�
        if (mash.size() == 2)
            answer = Min(answer, Abs(mash[0] - mash[1]));

        mash.clear(); //�� ���� �ʱ�ȭ
    }

    return answer;
}