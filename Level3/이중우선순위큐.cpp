#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    char op;
    int number;
    answer.push_back(0);
    answer.push_back(0);
    for (int i = 0; i < operations.size(); i++) {
        op = operations[i][0];
        //문자열 슬라이싱
        number = stoi(operations[i].substr(2));
        if (op == 'I') {
            dq.push_back(number);
            sort(dq.begin(), dq.end());
        }
        else if (!dq.empty()) {
            if (number == 1)
                dq.pop_back();
            else
                dq.pop_front();
        }
    }
    if (!dq.empty()) {
        answer[0] = dq.back();
        answer[1] = dq.front();
    }
    return answer;
}