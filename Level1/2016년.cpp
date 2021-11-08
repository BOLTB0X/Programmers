#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    // 1월 1일은 금요일이므로
    string days[7] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    int months[13] = { 0, 31, 29, 31, 30, 31, 30 , 31, 31, 30, 31, 30, 31 };
    int tot = 0;

    for (int i = 0; i < a; ++i)
        tot += months[i];

    tot += b - 1;
    answer = days[tot % 7];

    return answer;
}