#include <string>
#include <vector>
#include <queue> // queue, priority_queue

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size = priorities.size(); // 길이
    queue<int> que;
    priority_queue<int> pq; 
    
    for (int i = 0; i<size; ++i) {
        pq.push(priorities[i]);
        que.push(i);
    }
    
    while(!que.empty()) {
        int idx = que.front();
        que.pop();
        
        // 우선순위가 가장 높다면
        if(priorities[idx] == pq.top()) {
            answer++; // 배포
            
            if (idx == location) // 원하는 것이면
                break;
            
            else // 아니면
                pq.pop();
        }
        
        else // 다시 넣어둠
            que.push(idx);
    }
    
    return answer;
}
