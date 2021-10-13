#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    //남은 진행률
    vector<int> rest_p;
    //걸리는 시간
    vector<int> t;
    
    //남은 진행률 표시
    for (int i=0;i<progresses.size();++i) 
        rest_p.push_back(100-progresses[i]);
    
    //남은 진행률이 몇일 걸리는 지 확인
    for (int i=0;i<rest_p.size();++i) {
        //딱 나눠 떨어져 끝나면
        if (rest_p[i] % speeds[i] == 0) 
            t.push_back(rest_p[i] / speeds[i]);
        //그 외
        else
            t.push_back((rest_p[i] / speeds[i])+1);
    }
    //비교 날 셋팅
    int cmp_day = t[0];
    int cnt=1;
    
    //각 기간 내 같이 배포되는 수 확인
    for (int i=1;i<t.size();++i) {
        //앞에 일이 끝나지 않은 것
        //즉 큰 경우
        if (cmp_day >= t[i])
            cnt++;
        //드디어 작다면
        else {
            answer.push_back(cnt);
            cmp_day=t[i];
            cnt=1;
        }
    }
    //마지막은 처리가 안되니
    answer.push_back(cnt);
    //정답 반환
    return answer;
}
