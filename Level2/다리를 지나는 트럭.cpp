#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    //���� ����� �Ǵ� ���� �񱳿�
    int idx = 0;
    //�ٸ� �� ������ ����
    int weight_tot = 0;
    //�ٸ�
    queue<int> q;

    while (true) {
        //������ Ʈ���� ���
        if (idx == truck_weights.size()) {
            //������ Ʈ���� ������ �ð� �߰�
            answer += bridge_length;
            break;
        }
        answer++;
        //���� �ٸ��� �� �ǳ��� ���
        if (q.size() == bridge_length) {
            weight_tot -= q.front();
            q.pop();
        }
        //�ٸ��� ���� ������ �����Ҷ�
        if (weight_tot + truck_weights[idx] <= weight) {
            weight_tot += truck_weights[idx];
            q.push(truck_weights[idx]);
            idx++;
        }
        //���� �� �� ���ٸ�
        else {
            q.push(0);
        }
    }
    return answer;
}