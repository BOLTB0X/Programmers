#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    string tmp_s = "";
    vector<string> tmp_arr;
    //���⸦ �������� ������ ���Ϳ� ����
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            tmp_s += s[i];
        }
        else {
            tmp_arr.push_back(tmp_s);
            tmp_s = "";
        }
    }
    //������ �ܾ� ����
    tmp_arr.push_back(tmp_s);

    for (int i = 0; i < tmp_arr.size(); i++) {
        tmp_s = tmp_arr[i];
        //ù��° ���ڰ� �ҹ��ڸ�
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
