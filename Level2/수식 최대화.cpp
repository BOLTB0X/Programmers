#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//�����ں� ���
long long calculate(long long a, long long b, char op) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> numbers;
    vector<char> op_types = { '*','+','-' };
    vector<char> op;
    string tmp_num = "";

    //��ǲ ���ڿ� ���� op �и�
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
            op.push_back(expression[i]);
            numbers.push_back(atoi(tmp_num.c_str()));
            tmp_num = "";
        }
        else
            tmp_num += expression[i];
    }
    //������ ������ ����
    numbers.push_back(atoi(tmp_num.c_str()));

    do {
        //������ �켱������ ���� ���
        vector<long long> tmp_numbers = numbers;
        vector<char> tmp_op = op;
        //����Ž�� ����
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < tmp_op.size(); j++) {
                if (tmp_op[j] == op_types[i]) {
                    tmp_numbers[j] = calculate(tmp_numbers[j], tmp_numbers[j + 1], op_types[i]);
                    tmp_numbers.erase(tmp_numbers.begin() + j + 1);
                    tmp_op.erase(tmp_op.begin() + j);
                    j--;
                }
            }
        }
        if (abs(tmp_numbers.front()) > answer)
            answer = abs(tmp_numbers.front());
    } while (next_permutation(op_types.begin(), op_types.end()));
    return answer;
}