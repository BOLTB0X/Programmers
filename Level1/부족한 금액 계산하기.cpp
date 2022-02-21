using namespace std;

long long solution(int price, int money, int count) {
    long long answer = 0, tot = 0;

    //총 금액
    for (int i = 1; i <= count; ++i)
        tot += (i * price);

    //부족하다면
    if ((money - tot) < 0)
        answer = tot - money;

    return answer;
}