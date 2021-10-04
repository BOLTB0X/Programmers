#include <string>
#include <vector>
#include <queue>

using namespace std;

//최소 힙을 위한 조건
struct compare {
    bool operator() (int x, int y) {
        return x > y;
    }
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //최소 힙
    priority_queue<int, vector<int>, compare> pq;

    //스코빌 지수 값을 우선순위 큐에 삽입
    for (int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);

    //힙이 원소가 2개이상 이고 K 이상이 될때까지 반복
    while (pq.size() > 1 && pq.top() < K) {
        int fir = pq.top();
        pq.pop();
        int sec = pq.top();
        pq.pop();
        pq.push(fir + (sec * 2));
        answer++;
    }
    //만약 반복문 후에도 스코빌지수가 낮다면
    if (pq.top() < K) {
        answer = -1;
    }
    return answer;
}
