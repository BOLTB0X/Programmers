#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end()); //오름차순
    int head = 0;
    int tail = people.size() - 1;
    while (head <= tail) {
        if (people[head] + people[tail] <= limit) {
            head += 1;
            tail -= 1;
        }
        else
            tail -= 1;
        answer++;
    }
    return answer;
}