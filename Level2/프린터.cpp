#include <string>
#include <vector>
#include <queue>

using namespace std;

int max(deque<int> arr) {
    int max_value = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (max_value < arr[i]) {
            max_value = arr[i];
        }
    }
    return max_value;
}

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    int idx = 0;
    
    //q와 pq 값 할당
    for (const auto& p : priorities) {
        q.push({ idx++,p });
        pq.push(p);
    }

    int prior = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front();

        if (pq.top() <= cur.second) {
            if (cur.first == location) {
                return prior;
            }
            q.pop();
            pq.pop();
            prior++;
        }
        else {
            q.push(cur);
            q.pop();
        }
    }
}