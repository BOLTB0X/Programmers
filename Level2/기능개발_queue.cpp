#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> que; // 큐
    
    // 순번 저장
    for (int i = 0; i< progresses.size(); ++i) 
        que.push(i);
    
    // 큐가 빌때까지
    while(!que.empty()) {
        int cnt = 0;
        
        for (int i = 0; i < progresses.size(); ++i) 
            progresses[i] += speeds[i];
        
        // 배포되는 것을 체크
        while(!que.empty() && progresses[que.front()] >= 100) {
            cnt++;
            que.pop();
        }
        // 배포가 되었으면
        if (cnt > 0)
            answer.push_back(cnt);
    }
    
    return answer;
}
