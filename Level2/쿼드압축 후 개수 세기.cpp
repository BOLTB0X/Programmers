#include <string>
#include <vector>

using namespace std;

//결과
vector<int> ret(2, 0);

//분할정복으로 압축
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

    //쿼드 압축이 된 것이므로
    if (flag) {
        if (cmp == 1)
            ret[1]++;
        else
            ret[0]++;
        return;
    }

    //분할정복
    //분할 범위 반으로
    check_Compression(arr, y, x, half, arr[y][x]);
    // 한칸 전진
    check_Compression(arr, y + half, x, half, arr[y + half][x]);
    check_Compression(arr, y, x + half, half, arr[y][x + half]);
    //대각선 전진
    check_Compression(arr, y + half, x + half, half, arr[y + half][x + half]);
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    check_Compression(arr, 0, 0, arr.size(), arr[0][0]);
    answer = ret;
    return answer;
}