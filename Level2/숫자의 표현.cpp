#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;

    int start = 1; //1로 시작
    // 시작값이 n보다 커지기 전까지 반복
    while (start <= n) {
        int tmp = 0; //임시 합변수
        int tmp_idx = start; //임시 시작값
        while (true) { //셋팅된 시작값으로 루프 시작
            //임시 합 변수가 n과 값다면
            if (n == tmp) {
                answer += 1; //카운트
                break; //루프 탈출
            }
            // 임시합이 n보다 커지면 
            else if (n < tmp) break; //루프 탈출
            tmp += tmp_idx; 
            tmp_idx++;
        }
        start++;
    }
    return answer;
}