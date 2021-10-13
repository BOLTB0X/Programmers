#include <string>
#include <vector>
#include <queue>

using namespace std;

//최소 힙을 위한
struct compare {
    bool operator() (int& a, int& b) {
        return a > b;
    }
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //우선순위 큐 선언
    priority_queue<int, vector<int>, compare> pq;
    //우선순위 큐에 넣어줌
    for (int i = 0; i < scoville.size(); ++i)
        pq.push(scoville[i]);

    //스코빌 지수가 맞춰질때
    //섞는 조건이 2개가 필요하므로
    //즉 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복해야함
    while (pq.top() < K && pq.size() > 1) {
        //문제 조건
        int fir_elem = pq.top();
        pq.pop();
        int sec_elem = pq.top();
        pq.pop();
        //섞은 음식의 스코빌 지수 
        pq.push(fir_elem + (sec_elem * 2));
        answer++;
    }

    //만약 최상단이 아직도 K미만이면
    if (pq.top() < K) {
        answer = -1;
    }
    return answer;
}
