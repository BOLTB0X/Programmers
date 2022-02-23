#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int size = progresses.size();
    vector<int> answer, works;
    
    //남은 작업량
    for (int i = 0; i < size; ++i) {
        int p = 100 - progresses[i];
        if ((p % speeds[i]) == 0)
            works.push_back(p / speeds[i]);
        else
            works.push_back((p / speeds[i]) + 1);
    }
    
    //비교 및 카운트
    int cur_work = works[0], cnt = 1;
    
    for (int i = 1; i <size; ++i) {
        if (cur_work >= works[i])  //현재 작업량이 끝났다면
            cnt++;
        
        else { //교체
            answer.push_back(cnt);
            cur_work = works[i];
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}
