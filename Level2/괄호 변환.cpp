#include <string>
#include <vector>

using namespace std;

//�ùٸ� ��ȣ�ΰ�?
int is_Correct(string s) {
    int cnt = 0;
    //stack<char> st; �������ΰ� �����̹Ƿ� ������ ���� ��
    for (char& c : s) {
        //�����̸�
        if (c == '(')
            cnt++;
        else {
            //Ŭ����� ž�� �����ϰ��
            if (cnt == 0)
                return 0;
            cnt--;
        }
    }
    //���ʿ� ���ڿ��� ������������
    //�� ��ȯ
    return 1;
}

//Ư���κ� �ε��� ��ȯ
int get_split_idx(string w) {
    int cnt = 0;
    int size = w.length();

    for (int i = 0; i < size; ++i) {
        if (w[i] == '(')
            cnt++;
        else
            cnt--;

        if (cnt == 0)
            return i;
    }
    return -1;
}

string solution(string p) {
    string answer = "";
    string u = "", v = "";

    // 1��
    if (p == "")
        return "";

    // 2��
    int idx = get_split_idx(p);
    u = p.substr(0, idx + 1);
    v = p.substr(idx + 1);

    // 3��
    if (is_Correct(u) == 1)
        answer = u + solution(v);
    // 4��
    else {
        answer += "("; // 4 - 1
        answer += solution(v); // 4 - 2
        answer += ")"; // 4 - 3

        // 4 - 4
        u = u.substr(1, u.size() - 2);

        // 4 - 5
        for (int i = 0; i < u.size(); ++i) {
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
        answer += u; // 4 - 5
    }

    return answer;
}