#include <string>
#include <vector>
#define MS 300001 //최대 길이

using namespace std;

long long result = 0;
vector<long long> adj[MS];

long long Abs(long long a) {
    return a < 0 ? -a : a;
}

//깊이우선탐색
void DFS(vector<long long>& weights, int size, int cur, int parent) {
    // /리에 대해서 해당 사항이 가능한지 판별 -> 먼저 탐색
    for (long long& next: adj[cur]) {
        //즉 부모가 다르다면 노드 이동을 한다는 것
        if (next != parent)
            DFS(weights, size, next, cur); //현재가 부모노드가 됨
    }
    
    weights[parent] += weights[cur]; //0으로 만들기
    result += Abs(weights[cur]); 
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    int size = a.size(); //노드의 갯수
    
    //가중치
    vector<long long> weights(size + 1, 0);

    for (int i = 0; i < size; ++i) 
        weights[i] = a[i];
    
    //인접리스트 생성
    for (vector<int>& e: edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    //호출
    DFS(weights, size, 0, 0);
    
    //불가능한 경우
    if (weights[0] != 0)
        answer = -1;
    else
        answer = result;
    return answer;
}
