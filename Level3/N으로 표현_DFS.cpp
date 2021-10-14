#include <string>
#include <vector>

using namespace std;

int result = 9;

//�ּڰ� ��
int min(int a, int b) {
    return a < b ? a : b;
}

//���� �켱 Ž��
void DFS(int n, int number, int tot, int depth) {
    //8���� ũ�� �ȵǹǷ�
    if (depth >= 9)
        return;
    //������� ���� Ÿ�ٰ� ��������
    if (tot == number) {
        result = min(result, depth);
        return;
    }
    int r = 0;
    //�ִ� �ݺ� Ƚ����ŭ �ݺ�
     //n���� nn,nnn,nnn ..
    //n �� ������ ���̰� nn �ڿ� ���̰� �ݺ�
    for (int i = 0; i + depth < 9; ++i) {
        r = r * 10 + n;
        DFS(n, number, tot + r, depth + 1 + i);
        DFS(n, number, tot - r, depth + 1 + i);
        DFS(n, number, tot * r, depth + 1 + i);
        DFS(n, number, (int)tot / r, depth + 1 + i);
    }
}

int solution(int N, int number) {
    int answer = 0;

    //DFS
    DFS(N, number, 0, 0);

    //8���� ũ��
    if (result > 8)
        answer = -1;
    else
        answer = result;
    return answer;
}