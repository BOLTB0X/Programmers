#include <string>
#include <vector>

using namespace std;

//���
vector<int> ret(2, 0);

//������������ ����
void check_Compression(vector<vector<int>>& arr, int y, int x, int size, int cmp) {
    int half = size / 2;
    bool flag = 1;

    if (size < 2) {
        if (cmp == 1)
            ret[1]++;
        else
            ret[0]++;
        return;
    }

    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (arr[i][j] != cmp) {
                flag = 0;
                break;
            }
        }
        if (!flag)
            break;
    }

    //���� ������ �� ���̹Ƿ�
    if (flag) {
        if (cmp == 1)
            ret[1]++;
        else
            ret[0]++;
        return;
    }

    //��������
    //���� ���� ������
    check_Compression(arr, y, x, half, arr[y][x]);
    // ��ĭ ����
    check_Compression(arr, y + half, x, half, arr[y + half][x]);
    check_Compression(arr, y, x + half, half, arr[y][x + half]);
    //�밢�� ����
    check_Compression(arr, y + half, x + half, half, arr[y + half][x + half]);
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    check_Compression(arr, 0, 0, arr.size(), arr[0][0]);
    answer = ret;
    return answer;
}