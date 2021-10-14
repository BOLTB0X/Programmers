#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    //100 - 진도율 
    vector<int> rest_progresses;
    //걸리는 일수
    vector<int> day;
    
    for (int i=0;i<progresses.size();++i) 
        rest_progresses.push_back(100-progresses[i]);
    
    //남은 진도율을 알았으니 스피드와 나누어떨어지는 것을
    //비교하며 걸리는 일수를 저장함
    for (int i=0;i<rest_progresses.size();++i) {
        if (rest_progresses[i] % speeds[i] == 0)
            day.push_back(rest_progresses[i] / speeds[i]);
        else 
            day.push_back((rest_progresses[i] / speeds[i])+1);
    }
    
    //비교용
    int compare = day[0];
    int cnt=1;
    for (int i=1;i<day.size();++i) {
        //앞에 진도율이 끝나지 않았다면
        //작업 한 후 배포이므로
        if (compare >= day[i]) 
            cnt++;
        else {
            //배포 후 비교랑 같이 배포되는 프로그램 갯수 초기화
            answer.push_back(cnt);
            cnt=1;
            compare=day[i];
        }
    }
    //마지막은 처리가 안되니 
    answer.push_back(cnt);
    
    return answer;
}
