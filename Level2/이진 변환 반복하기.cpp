#include <string>
#include <vector>

using namespace std;

int t_cnt = 0, z_cnt = 0;

//길이 반환
int get_len(string s) {
    int ret = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0')
            z_cnt++;
        else if (s[i] == '1')
            ret++;
    }

    return ret;
}

//2진수 반환
string get_bin(int len) {
    string tmp = "", ret = "";

    while (len > 0) {
        int r = len % 2;
        tmp += (char)(r + '0');
        len /= 2;
    }

    for (int i = tmp.length() - 1; i >= 0; --i)
        ret += tmp[i];

    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;

    while (1) {
        //탈출조건
        if (s == "1")
            break;

        t_cnt++;
        s = get_bin(get_len(s));
    }

    answer.push_back(t_cnt);
    answer.push_back(z_cnt);
    return answer;
}
