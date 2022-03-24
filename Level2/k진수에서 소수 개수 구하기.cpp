#include <string>
#include <vector>

using namespace std;

// �Ҽ� �Ǻ�
int prime(long long p) {
    if (p == 0 || p == 1)
        return 0;

    for (long long i = 2; i * i <= p; ++i) {
        if (p % i == 0)
            return 0;
    }
    return 1;
}

string trans_number(int n, int k) {
    string number = "";

    while (n > 0) {
        int r = n % k;

        number += (char)(r + '0');
        n /= k;
    }

    return string(number.rbegin(), number.rend());
}

int solution(int n, int k) {
    int answer = 0;
    // ��ȯ
    string ret = trans_number(n, k);
    long long size = ret.size(); // ����
    string tmp = "";

    for (long long i = 0; i < size; ++i) {
        if (ret[i] == '0' && tmp.length() != 0) {
            long long p = stoll(tmp); // ��ȯ

            // �Ҽ��̸�
            if (prime(p) == 1)
                answer++;
            tmp = ""; // �ʱ�ȭ
        }
        else
            tmp += ret[i];
    }
    if (tmp.length() != 0) {
        long long p = stoll(tmp); // ��ȯ

        // �Ҽ��̸�
        if (prime(p) == 1)
            answer++;
    }

    return answer;
}