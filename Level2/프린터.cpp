#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    //우선순위 큐 선언
    priority_queue<int> pq;
    
    //큐 선언, 우선순위와 기존 위치=idx까지
    queue<pair<int,int>> q;
    
    //우선순위를 pq,q에 옮겨줌
    for (int i=0;i<priorities.size();++i) {
        pq.push(priorities[i]);
        q.push({priorities[i],i});
    }
    
    //우선순위 큐가 내림차순으로 정렬됨
    //원하는 위치가 몇번째로 뽑히는 지가 궁금하므로
    //일반 큐의 i와 원하는 위치를 비교
    int order = 1;
    while (!q.empty()) {
        //같이 크거나 같다면 
        if (pq.top() <= q.front().first) {
            // 원하는 위치까지 같다면
            if(location == q.front().second)
                //반복문 중단
                break;
            //위치가 다르다면
            order++;
            pq.pop();
            q.pop();
        }
        //작다면
        else {
            //큐를 회전시킴
            q.push(q.front());
            q.pop();
        }
    }
    
    //정답 교체
    answer = order;
    
    //반환
    return answer;
}
