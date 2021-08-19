#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> tmp_v ;
    vector<int> day;
    //얼마나 남았는지 확인
    for (int i = 0; i < progresses.size(); i++) {
        tmp_v.push_back(100 - progresses[i]);
    }
    //몇일 걸리는지 확인
    for (int i = 0; i < tmp_v.size(); i++) {
        if (tmp_v[i] % speeds[i] == 0) {
            day.push_back(tmp_v[i] / speeds[i]);
        }
        else 
            day.push_back((tmp_v[i] / speeds[i])+1);
    }
    int sample_day = day[0];
    int cnt = 1;
    //각 기간내 같이 배포되는지 확인
    for (int i = 1; i < day.size(); i++) {
        if (sample_day >= day[i]) 
            cnt += 1;
        else {
            answer.push_back(cnt);
            sample_day = day[i];
            cnt = 1;
        }
    }
    //마지막은 삽입이 안되니
    answer.push_back(cnt);

    return answer;
}