#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct compare {
    bool operator() (int x, int y) {
        return x > y;
    }
};

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,compare> pq;

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    while (pq.size() > 1 && pq.top() < K) {
        int tmp_fir = pq.top();
        pq.pop();
        int tmp_sec = pq.top();
        pq.pop();
        pq.push(tmp_fir + (tmp_sec * 2));
        answer++;
    }
    if (pq.top() < K)
        answer = -1;
    return answer;
}