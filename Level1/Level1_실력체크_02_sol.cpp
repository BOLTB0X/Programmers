#include <string>
#include <vector>
using namespace std;

int get_int(string n) {
    int tot = 0;

    for (int i = 0; i < n.length(); ++i)
        tot = tot * 10 + (int)(n[i] - '0');
    return tot;
}

int solution(string dartResult) {
    int answer = 0;
    // S-> 1, D -> 2, T -> 3
    // * -> 2��, # -> ���̳ʽ�
    // *�� ù ��°�� ������ 2��
    // *�� ��ø�� �� ��� 4�� 4��
    // *#�� ��� -2�� 5��
    int size = dartResult.length();
    vector<int> v;
    string tmp = "";
    int flag = 0; // �ٸ� ��ȣ���� ���Դ� �� üũ

    for (int i = 0; i < size; ++i) {
        if (dartResult[i] == 'S') {
            int number = get_int(tmp);
            v.push_back(number);
            tmp = "";
        }

        else if (dartResult[i] == 'D') {
            int number = get_int(tmp);
            number = number * number;
            v.push_back(number);
            tmp = "";
        }

        else if (dartResult[i] == 'T') {
            int number = get_int(tmp);
            number = number * number * number;
            v.push_back(number);
            tmp = "";
        }

        else if (dartResult[i] == '*') {
            if (v.size() == 1)
                v[0] = v[0] * 2;

            else {
                for (int i = v.size() - 2; i < v.size(); ++i)
                    v[i] = v[i] * 2;
            }
        }

        else if (dartResult[i] == '#')
            v[v.size() - 1] = -v[v.size() - 1];

        else
            tmp.push_back(dartResult[i]);
    }

    for (int i = 0; i < v.size(); ++i)
        answer += v[i];

    return answer;
}