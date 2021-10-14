#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//벡터 슬라이딩
int vector_sliding(vector<int>& array, int start, int end, int idx) {
    //comm는 3으로 고정
    vector<int> partial_arr;

    //탐색
    for (int i = start - 1; i < end; ++i)
        partial_arr.push_back(array[i]);

    //오름차순 정렬
    sort(partial_arr.begin(), partial_arr.end());

    //타겟 반환
    return partial_arr[idx - 1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    //배열을 잘라야함
    for (int i = 0; i < commands.size(); ++i) {
        //벡터 슬라이딩을 하여 해당 값을 받은 후
        int ret = vector_sliding(array, commands[i][0], commands[i][1], commands[i][2]);
        //정답 백터에 삽입
        answer.push_back(ret);
    }
    return answer;
}