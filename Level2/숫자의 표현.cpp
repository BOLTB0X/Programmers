#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    //최대 반복지점 == 연속되는 자연수의 합 중 가장 끝에 일치하는 값
    //즉 절반이상은 의미가 없음
    int num = (n + 1) / 2;
    int tot = 0, j = 1;
    for (int i = 1; i <= num; i++) {
        tot += i; //차근차근 더함
        if (tot >= n)
            while (tot > n)
                tot -= j++; //역으로 빼줌
        if (tot == n)
            answer++;
    }
    return answer;
}