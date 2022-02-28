#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; ++i) {
        int cnt = 0;
        //각 약수 갯수 확인
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0)
                cnt++;
        }
        
        if (cnt % 2 == 0) //짝수
            answer += i;
        else //홀수
            answer -= i;
    }
    //반환
    return answer;
}
