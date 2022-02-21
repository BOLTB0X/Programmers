#include <string>
#include <vector>
#include <algorithm> //���Ŀ�

using namespace std;

vector<string> per;
char moum[5] = { 'A', 'E', 'I', 'O', 'U' };

void DFS(string word, int leng) {
    //Ż������
    if (word.length() == leng) {
        per.push_back(word);
        return;
    }

    //�ߺ�����ó�� 
    for (char& m : moum)
        DFS(word + m, leng);
    return;
}

int solution(string word) {
    int answer = 0;

    //�� ��Ʈ��ŷ���� ������ ���� ��� �ܾ� ������ ����
    for (int i = 1; i <= 5; ++i) {
        string tmp_word = "";
        DFS(tmp_word, i);
    }

    //�ܾ� ������ A, E, I ..... AA �� �����־� ������ �ʿ�
    sort(per.begin(), per.end());

    for (int i = 0; i < per.size(); ++i) {
        if (word == per[i]) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}