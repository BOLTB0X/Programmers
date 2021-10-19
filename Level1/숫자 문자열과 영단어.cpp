#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> trans;

//설정
void setting_trans(void) {
    trans["zero"] = "0";
    trans["one"] = "1";
    trans["two"] = "2";
    trans["three"] = "3";
    trans["four"] = "4";
    trans["five"] = "5";
    trans["six"] = "6";
    trans["seven"] = "7";
    trans["eight"] = "8";
    trans["nine"] = "9";
    return;
}

int solution(string s) {
    int answer = 0;
    setting_trans();

    string idx = "";
    string result = "";

    //문자열 탐색
    for (int i = 0; i < s.length(); ++i) {
        //정수이면
        if (isdigit(s[i]))
            result += s[i];
        else {
            idx += s[i];
            //idx가 숫자네임이 되면
            if (trans[idx] != "") {
                result += trans[idx];
                idx = "";
            }
        }
    }
    //문자열 정수로 변환
    answer = stoi(result);
    return answer;
}