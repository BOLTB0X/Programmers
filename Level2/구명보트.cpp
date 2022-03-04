#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int size = people.size();

    int left = 0, right = size - 1;
    sort(people.begin(), people.end()); //오름 차순
    
    while(left <= right) {
        //한명만 데리고 가는 경우
        if (people[left] + people[right] > limit) 
            right--;
        
        //둘 다
        else {
            left++;
            right--;
        }
        answer++;
    }
    
    return answer;
}
