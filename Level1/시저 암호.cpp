#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (s[i] + n - 'A') % 26 + 'A';
            answer += s[i];
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = (s[i] + n - 'a') % 26 + 'a';
            answer += s[i];
        }
        else if (s[i] == ' ')
            answer += ' ';
    }
    return answer;
}