#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    string tmp = "";
    int cnt = 0;
    
    //거꾸로 탐색
    for (int i = phone_number.length() - 1; i >= 0; --i) {
        if (cnt < 4) {
            tmp += phone_number[i];
            cnt++;
        }
        else
            tmp += '*';
    }

    //다시 거꾸로
    for (int i = tmp.length() - 1; i >= 0; --i)
        answer += tmp[i];

    //반환
    return answer;
}