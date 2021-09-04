#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    if (n == 1 || n == 0)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v;
    //���ڿ� ���Ҹ� ���Ϳ� ����
    for (int i = 0; i < numbers.size(); i++)
        v.push_back(numbers[i]);

    //���� �������� ����
    sort(v.begin(), v.end());

    //v���ͷ� ���� �� �ִ� ���� ���� ���� ����
    vector<int> per;
    //����� �� Ž�� ����
    do {
        string tmp = "";
        for (int i = 0; i <= v.size(); i++) {
            //���� �� �ִ� ��� ���� per�� ����
            tmp.push_back(v[i]);
            per.push_back(stoi(tmp));
        }
    } while (next_permutation(v.begin(), v.end()));
    //���� ���� ����
    sort(per.begin(), per.end());
    //�ߺ��� ����
    per.erase(unique(per.begin(), per.end()), per.end());

    for (int i = 0; i < per.size(); i++) {
        if (is_prime(per[i])) {
            answer++;
        }
    }
    return answer;
}