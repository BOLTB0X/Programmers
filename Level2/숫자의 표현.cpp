#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    //�ִ� �ݺ����� == ���ӵǴ� �ڿ����� �� �� ���� ���� ��ġ�ϴ� ��
    //�� �����̻��� �ǹ̰� ����
    int num = (n + 1) / 2;
    int tot = 0, j = 1;
    for (int i = 1; i <= num; i++) {
        tot += i; //�������� ����
        if (tot >= n)
            while (tot > n)
                tot -= j++; //������ ����
        if (tot == n)
            answer++;
    }
    return answer;
}