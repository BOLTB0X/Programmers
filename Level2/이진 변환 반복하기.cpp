#include <string>
#include <vector>

using namespace std;
int zero_cnt = 0;

int get_s_len(string s) {
    int len = 0; //±Ê¿Ã
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1')
            len += 1;
        else
            zero_cnt += 1;
    }
    return len;
}

string get_binary(int n) {
    string res = "";
    while (n >= 1) {
        int r = n % 2;
        res += char(r + '0');
        n /= 2;
    }
    return res;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    while (1) {
        if (s == "1")
            break;
        cnt++;
        s = get_binary(get_s_len(s));
    }
    answer.push_back(cnt);
    answer.push_back(zero_cnt);
    return answer;
}