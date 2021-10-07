#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    //차량 지목용 또는 길이 비교용
    int idx = 0;
    //다리 위 차들의 무게
    int weight_tot = 0;
    //다리
    queue<int> q;

    while (true) {
        //마지막 트럭인 경우
        if (idx == truck_weights.size()) {
            //마지막 트럭이 지나는 시간 추가
            answer += bridge_length;
            break;
        }
        answer++;
        //차가 다리를 다 건넜을 경우
        if (q.size() == bridge_length) {
            weight_tot -= q.front();
            q.pop();
        }
        //다리에 다음 차량이 진입할때
        if (weight_tot + truck_weights[idx] <= weight) {
            weight_tot += truck_weights[idx];
            q.push(truck_weights[idx]);
            idx++;
        }
        //진입 할 수 없다면
        else {
            q.push(0);
        }
    }
    return answer;
}