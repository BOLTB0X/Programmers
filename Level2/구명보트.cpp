#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    //오름차순 정렬
    sort(people.begin(), people.end());
    
    //이분탐색처럼 스타트와 끝을 정의
    int start = 0;
    int end = people.size() - 1;

    //엇갈리기 전까지
    while (start <= end) {
        //둘다 데려가는 경우
        if (people[start] + people[end] <= limit) {
            start++;
            end--;
        }
        //한놈만
        else
            end--;
        answer++;
    }

    return answer;
}
