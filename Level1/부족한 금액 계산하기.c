#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = -1;
    long long tot = 0;

    for (int i = 1; i <= count; ++i)
        tot += (price * i);

    if ((money - tot) > 0)
        answer = 0;
    else
        answer = (tot - money);

    return answer;
}