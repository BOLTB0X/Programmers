#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MS 100000001 //최대 길이

char str[MS] = {'\0',}; //편의를 위해 널로 초기화
int idx = 0;

//10진법 -> 3진법 변환
void trans_Ternary(int number) {
    int tmp = number;
    
    //0이 되기 전까지
    while (tmp > 0) {
        int mod = tmp % 3;
        str[idx++] = mod + '0';
        tmp /= 3;
    }
    //어차피 앞뒤 반전해야하므로
    return;
}

//3진법 - > 10진법 
int trans_dec(void) {
    int dec = 0;
    
    for(int i = idx - 1, j = 1; i>=0; --i, j *= 3)
        dec += j*(str[i] - '0');
    
    return dec;
}

int solution(int n) {
    int answer = 0;
    
    trans_Ternary(n);
    answer = trans_dec();
    
    return answer;
}
