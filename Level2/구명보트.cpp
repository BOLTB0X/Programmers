#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    //그리디알고리즘을 위한 오름차순 정렬
    sort(people.begin(), people.end());
    
    //앞 뒤로 순차적으로 탐색
    int front = 0, back = people.size() - 1;
    while (front <= back) {
        //한놈만
        if (people[front] + people[back] > limit) {
            back--;
        }
        
        //둘다
        else {
            front++;
            back--;
        }
        
        //카운트
        answer++;
    }
    
    return answer;
}
