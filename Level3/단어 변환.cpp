#include <string>
#include <vector>

using namespace std;

int result = 51;

//�ּ�
int min(int a, int b) {
    return a < b ? a : b;
}

//��ȯ���� �ٸ� ���ڰ� 1������ �Ǻ�
bool get_trans_cnt(string& begin, string& st) {
    int occ_cnt = 0;
    //���ڿ� Ư�� ��, ���� Ž��
    for (int j = 0; j < st.length(); j++) {
        //���۴ܾ�� Ž�� �ܾ�� ���� ī��Ʈ
        if (begin[j] != st[j])
            occ_cnt++;
        //2�� �̻��̸� ��ȯ�Ұ�
        if (occ_cnt == 2)
            return false;
    }
    //�ٸ� ���ڰ� 1�� �̸�
    return true;
}

//DFS����
void DFS(string begin, string target, vector<string>& words, vector<bool>& visited, int cnt) {
    //Ż�� ����
    if (begin == target) {
        result = min(result, cnt);
        return;
    }
    //���ڿ� ��
    for (int i = 0; i < words.size(); i++) {
        //��ȯ������ �Ǹ�
        if (get_trans_cnt(begin, words[i])) {
            //�̹湮 --> �� ��ȯ�Ҽ� �ִ� ������
            if (!visited[i]) {
                visited[i] = true;
                //�� �ش� �ܾ�� �̵�
                DFS(words[i], target, words, visited, cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    //�湮���� ���� �� �ʱ�ȭ
    vector<bool> visited(words.size(), false);
    //DFS�� Ž�� ����
    DFS(begin, target, words, visited, 0);
    answer = result;
    if (answer == 51)
        return 0;
    return answer;
}