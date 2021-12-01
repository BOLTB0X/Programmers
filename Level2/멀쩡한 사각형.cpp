#include <iostream>

using namespace std;

//최대공약수
int gcd(int w, int h) {
    if (w % h == 0)
        return h;
    else
        return gcd(h, w % h);
}

long long solution(int w, int h) {
    long long answer = 1;

    //대각선으로 내려갈때 w와 h의 최대공약수 만큼 반복하며 내려감
    //가로 세로가 w,h의 최대공약수만큼 반복하므로 
    //가로 세로는 w,h를 최대공약수로 나눈 값
    //잘라지는 사각형의 갯수는 (가로 + 세로 - 1) * 최대공약수

    //(w*h)-(w+h-최대공약수)

    answer = (long long)w * (long long)h - (w + h);
    answer += gcd(w, h);

    return answer;
}