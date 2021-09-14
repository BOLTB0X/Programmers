#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string tmp = "";
    if (s[0] == '-') {
        for (int i = 1; i < s.length(); i++) {
            tmp += s[i];
        }
        answer = -atoi(tmp.c_str());
    }
    else {
        for (int i = 0; i < s.length(); i++) {
            tmp += s[i];
        }
        answer = atoi(tmp.c_str());
    }
    return answer;
}