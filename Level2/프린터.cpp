#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q; 
    priority_queue<int> pq;
    int idx = 0;
    
    //q와 pq 값 할당
    for (const auto& p : priorities) {
        q.push({ idx++,p }); // 인덱스와 우선도
        pq.push(p); //우선순위 큐에 우선도 삽입
    }

    int order = 1; //나오는 순서
    while (!q.empty()) {
        pair<int, int> cur = q.front(); //큐 최상단
        //우선순위 큐의 상단이 작다면
        if (pq.top() <= cur.second) {
            //최상단이 원하는 위치이면
            if (cur.first == location) {
                return order;
            }
            q.pop();
            pq.pop();
            order++;
        }
        else {
            //현재 위치를 제일 마지막으로
            q.push(cur);
            q.pop();
        }
    }
}
