#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int size = progresses.size();

    //일 번호 큐에 푸쉬
    for (int i = 0; i < size; ++i)
        q.push(i);
    
    //연산 시작
    while (!q.empty()) {
        int cnt = 0;
        //계속 진도율을 더해줌
        for (int i = 0; i < size; ++i)
            progresses[i] += speeds[i];

        //배포가능한지 체크
        //최상단이 배포가능이 되어야함
        while (!q.empty() && progresses[q.front()] >= 100) {
            cnt++;
            q.pop();
        }
        if (cnt != 0)
            answer.push_back(cnt);
    }
    return answer;
}