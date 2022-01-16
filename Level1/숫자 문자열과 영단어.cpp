#include <string>
#include <vector>

using namespace std;

string trans(string& s) {
    if (s == "zero")
        return "0";
    else if (s == "one")
        return "1";
    else if (s == "two")
        return "2";
    else if (s == "three")
        return "3";
    else if (s == "four")
        return "4";
    else if (s == "five")
        return "5";
    else if (s == "six")
        return "6";
    else if (s == "seven")
        return "7";
    else if (s == "eight")
        return "8";
    else if (s == "nine")
        return "9";
    else
        return "-1";
}

int solution(string s) {
    long long answer = 0;
    string result = "";
    string idx = "";

    for (long long i = 0; i < s.length(); ++i) {
        if (isdigit(s[i]))
            result += s[i];
        else {
            idx += s[i];
            string tmp = trans(idx);
            if (tmp != "-1") {
                result += tmp;
                idx = "";
            }
        }
    }
    answer = stoll(result);
    return answer;
}