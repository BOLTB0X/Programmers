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

vector<int> mash; //망
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

void BFS(int n, int start, int y, int x) {
    int max_dist = -1; //최댓값을 위해
    visited[start] = 1;
    fr = 0, re = 0; //큐 초기화
    enqueue({ start, 0 });

    while (fr < re) {
        Node cur = dequeue();

        for (int& next : adj[cur.idx]) {
            //재방문
            if (visited[next] == 1)
                continue;

            //제외 노드들
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
            BFS(n, j, y, x);
        }

        //둘로 나눠졌다면
        if (mash.size() == 2)
            answer = Min(answer, Abs(mash[0] - mash[1]));

        mash.clear(); //망 벡터 초기화
    }

    return answer;
}