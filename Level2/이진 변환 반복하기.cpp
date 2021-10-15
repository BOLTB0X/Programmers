#include <string>
#include <vector>

using namespace std;
//0제거 횟수
int zero_cnt = 0;

//0을 제거한 이진수 문자열의 길이반환
int get_s_len(string s) {
    int len = 0;
    for (int i = 0; i < s.length(); i++) {
        //1의 갯수가 곧 길이
        if (s[i] == '1')
            len += 1;
        else
            zero_cnt += 1;
    }
    return len;
}

//이진수로 변환
string get_binary(int n) {
    string res = "", bb = "";
    while (n >= 1) {
        int r = n % 2;
        res += char(r + '0');
        n /= 2;
    }
    //연산 특성상 이진수가 뒤집어져 있으므로 다시 뒤집음
    for (int i = res.length() - 1; i >= 0; i--) {
        bb += res[i];
    }
    return bb;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    while (s != "1") {
        //연산 시작
        cnt++;
        s = get_binary(get_s_len(s));
    }
    
    answer.push_back(cnt);
    answer.push_back(zero_cnt);
    return answer;
}
