#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> cnt(n + 1, 1); //카운트 벡터 생성 및 초기화
    
    //잃어버린 학생들 감소
    for (int& l: lost) 
        cnt[l]--;
    
    //여분이 있는 학생들 증가
    for (int& r: reserve)
        cnt[r]++;
    
    //해당 학생을 카운트
    for (int i = 1; i <= n; ++i) {
        //체육복이 없는 학생 발견
        if (cnt[i] == 0) {
            //첫 번째 학생이 아니고 <- 쪽에 여분이 있다면
            if (i != 1 && cnt[i - 1] >= 2) {
                cnt[i]++;
                cnt[i - 1]--;
            }
            //마지막 학생이 아니고 -> 쪽에 여분이 있다면
            else if (i != n && cnt[i + 1] >= 2) {
                cnt[i]++;
                cnt[i + 1]--;
            }
        }
    }
    
    //총 학생들 카운트
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] >= 1)
            answer++;
    }
    
    return answer;
}
