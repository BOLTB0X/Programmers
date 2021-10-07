#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    //최대
    priority_queue<int> pq;
    //기존 자리
    int idx = 0;
    //우선순위벡터를 큐와 우선순위큐에 넣어줌
    for (int i = 0; i < priorities.size(); i++) {
        q.push({ idx++,priorities[i] });
        pq.push(priorities[i]);
    }

    //반복문으로 정답반환
    int answer = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        //우선순위 >= 현위치
        if (cur.second >= pq.top()) {
            //원하는 위치이면 반환
            if (cur.first == location) {
                return answer;
            }
            //아니면 우선순위 뽑아줌
            q.pop();
            pq.pop();
            //순번도 증가
            answer++;
        }
        //최하단으로 이동
        else {
            q.push(cur);
            q.pop();
        }
    }
}
