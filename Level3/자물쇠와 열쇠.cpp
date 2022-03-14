#include <string>
#include <vector>

using namespace std;

// 2���� ����Ʈ 90�� ȸ���ϱ�
vector<vector<int>> rotate_90(vector<vector<int>>& v) {
    int n = v.size(); // �� ���� ���
    int m = v[0].size(); // �� ���� ���

    vector<vector<int> > result(n, vector<int>(m)); // ��� ����Ʈ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = v[n - 1 - j][i];
        }
    }
    return result;
}

// �ڹ����� �߰� �κ��� ��� 1���� Ȯ��
int check(vector<vector<int>>& board) {
    int n = board.size() / 3;

    //�˻� ����
    for (int i = n; i < n * 2; i++) {
        for (int j = n; j < n * 2; j++) {
            //0���� �ϸ� �ȵɼ��� ����
            if (board[i][j] != 1) 
                return 0;
        }
    }

    return 1;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
    int n = lock.size();
    int m = key.size();

    // �ڹ����� ũ�⸦ ������ 3��� ��ȯ -> �� ������ �ּڰ��� 3
    vector<vector<int> > board(n * 3, vector<int>(n * 3));

    // ���ο� �ڹ����� �߾� �κп� ������ �ڹ��� �ֱ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            board[i + n][j + n] = lock[i][j];
    }

    // 90���� ȸ��
    for (int r = 0; r < 4; ++r) {
        key = rotate_90(key); // ���� ȸ��
        for (int y = 0; y < n * 2; y++) {
            for (int x = 0; x < n * 2; x++) {

                // �ڹ��迡 ȸ���� ���踦 ���� �ֱ�
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) 
                        board[y + i][x + j] += key[i][j];
                }

                // ��Ȯ�� ��� �´��� �˻�
                if (check(board) == 1) 
                    return true;

                // �ڹ��迡�� ���踦 �ٽ� ����
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) 
                        board[y + i][x + j] -= key[i][j];
                }
            }
        }
    }

    return false;
}