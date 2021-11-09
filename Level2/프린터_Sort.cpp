#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//��������
bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max_idx = 0, front = -1;
    vector<int> sorted_priorities = priorities;

    //����
    sort(sorted_priorities.begin(), sorted_priorities.end(), compare);

    while (true) {
        front = (front + 1) % priorities.size();
        if (priorities[front] == sorted_priorities[max_idx]) {
            answer++;
            max_idx++;

            //Ż�� ����
            if (location == front)
                break;
        }
    }

    //��ȯ
    return answer;
}