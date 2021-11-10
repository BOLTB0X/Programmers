#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //체크용 벡터
    vector<int> check(n, 1);

    //잃어버린 학생들 감소
    for (auto l : lost)
        check[l - 1]--;
    
    //여분이 있는 학생들 증가
    for (auto r : reserve)
        check[r - 1]++;

    //체크 벡터 순회
    for (int i = 0; i < check.size(); ++i) {
        //만약 해당 학생이 체육복이 없다면
        if (check[i] == 0) {
            //이전 사람 확인
            if (i != 0 && check[i - 1] == 2) {
                check[i - 1]--;
                check[i]++;
            }  

            //다음 사람 확인
            else if (i != check.size() - 1 && check[i + 1] == 2) {
                check[i + 1]--;
                check[i]++;
            }
        }
    }

    //마지막 체육복이
    for (auto c : check)
        if (c != 0)
            answer++;

    //반환
    return answer;
}