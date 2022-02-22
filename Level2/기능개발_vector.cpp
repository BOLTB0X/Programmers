#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, works;
    int size = progresses.size(); //길이

    //남은 진도율 계산
    for (int i = 0; i < size; ++i) {
        int p = 100 - progresses[i];
        if (p % speeds[i] == 0)
            works.push_back(p / speeds[i]);
        else
            works.push_back((p / speeds[i]) + 1);
    }

    int cmp = works[0], cnt = 1; //비교용, 갯수

    for (int i = 1; i < size; ++i) {
        //앞에가 다 끝나지 않은 경우
        if (cmp >= works[i])
            cnt++;
        else {
            //배포 후 비교랑 같이 배포되는 프로그램 갯수 초기화
            answer.push_back(cnt);
            cnt = 1; //초기화
            cmp = works[i];
        }
    }

    //마지막은 처리가 안되므로
    answer.push_back(cnt);
    return answer;
}