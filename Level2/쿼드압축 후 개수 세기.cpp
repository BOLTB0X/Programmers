#include <string>
#include <vector>

using namespace std;

int one_cnt = 0, zero_cnt = 0;

void compress(vector<vector<int>> &arr, int size, int y, int x, int cmp) {
    int half = size / 2;
    int flag = 1; //체크용

    //2미만
    if (size < 2) {
        if (cmp == 1)
            one_cnt++;
        else
            zero_cnt++;
        return;
    }
    
    
    //분할로 확인
    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            //압축 실패
            if (arr[i][j] != cmp) {
                flag = 0;
                break;
            }
        }
        //압축 실패
        if (flag == 0)
            break;
    }
    
    //압축이 성공한 경우
    if (flag == 1) {
        if (cmp == 1)
            one_cnt++;
        else
            zero_cnt++;
        return;
    }
    
    // 압축이 안된 것이므로
    // 다시 분할
    compress(arr, half, y, x, arr[y][x]); // 길이를 다시 반으로
    compress(arr, half, y + half, x, arr[y + half][x]); // y
    compress(arr, half, y, x + half, arr[y][x + half]); // x
    compress(arr, half, y + half, x + half, arr[y + half][x + half]); //둘 다
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int size = arr.size(); //길이
    int y = 0, x = 0;
    
    //압축 시작
    compress(arr, size, y, x, arr[y][x]);
    
    answer.push_back(zero_cnt);
    answer.push_back(one_cnt);
    return answer;
}
