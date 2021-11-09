#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    //작업 일수
    vector<int> works;

    //남은 진도율과 스피드와 나누어 떨어지는 지 비교
    for (int i = 0;i < progresses.size(); ++i) {
        if ((100 - progresses[i]) % speeds[i] == 0)
            works.push_back((100 - progresses[i]) / speeds[i]);
        else
            works.push_back(((100 - progresses[i]) / speeds[i]) + 1);
    }
    
    //비교용
    int compare = works[0];
    //배포 기능
    int f=1;
    
    for (int i=1; i<works.size(); ++i) {
        //앞에 진도율이 끝나지 않았다면
        //작업 한 후 배포이므로
        if (compare >= works[i]) 
            f++;
        else {
            //배포 후 비교랑 같이 배포되는 프로그램 갯수 초기화
            answer.push_back(f);
            f=1;
            compare=works[i];
        }
    }
    
    //마지막 처리
    answer.push_back(f);
    
    //반환
    return answer;
}
