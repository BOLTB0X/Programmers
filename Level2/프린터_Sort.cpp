#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//내림차순
bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max_idx = 0, front = -1;
    vector<int> sorted_priorities = priorities;

    //정렬
    sort(sorted_priorities.begin(), sorted_priorities.end(), compare);

    while (true) {
        front = (front + 1) % priorities.size();
        if (priorities[front] == sorted_priorities[max_idx]) {
            answer++;
            max_idx++;

            //탈출 조건
            if (location == front)
                break;
        }
    }

    //반환
    return answer;
}