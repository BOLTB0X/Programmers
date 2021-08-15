#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    string tmp_s = "";
    vector<string> tmp_arr;
    //띄어쓰기를 기준으로 나눠서 벡터에 삽입
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            tmp_s += s[i];
        }
        else {
            tmp_arr.push_back(tmp_s);
            tmp_s = "";
        }
    }
    //마지막 단어 삽입
    tmp_arr.push_back(tmp_s);

    for (int i = 0; i < tmp_arr.size(); i++) {
        tmp_s = tmp_arr[i];
        //첫번째 문자가 소문자면
        if (tmp_s[0] >= 'a' && tmp_s[0] <= 'z') {
                tmp_s[0] = tmp_s[0] - 'a' + 'A';
        }
        for (int j = 1; j < tmp_s.length(); j++) {
            if (tmp_s[j] >='A' && tmp_s[j] <= 'Z')
                tmp_s[j] = tmp_s[j] - 'A' + 'a';
        }
        answer += tmp_s;
        if (i < tmp_arr.size() - 1) answer += ' ';
    }
    return answer;
}
