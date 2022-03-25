#include <string>
#include <vector>

using namespace std;

int result = 0;
vector<int> answer(1, -1); //초기값

int check(vector<int>& ryan) {
    for (int i = 10; i >= 0; --i) {
        if (ryan[i] > answer[i])
            return 1;
        else if (ryan[i] < answer[i])
            return 0;
    }
}

void get_Score(vector<int>& ryan, vector<int>& info) {
    int r_tot = 0, a_tot = 0;

    for (int i = 0; i < 11; ++i) {
        if (ryan[i] > info[i])
            r_tot += (10 - i);

        else if (info[i] > 0)
            a_tot += (10 - i);
    }

    int dif_value = r_tot - a_tot;
    if (dif_value > 0 && dif_value >= result) {
        if (dif_value == result && check(ryan) == 0)
            return;

        result = dif_value;
        answer = ryan;
    }
    return;
}

// DFS로 완전탐색
void DFS(vector<int>& ryan, int n, vector<int>& info, int idx) {
    // 벡터를 다 순회했거나 화살이 다 떨어진 경우
    if (idx == 11 || n == 0) {
        ryan[10] += n;
        get_Score(ryan, info);
        ryan[10] -= n;
        return;
    }

    // 득점을 했다면
    if (info[idx] < n) {
        ryan[idx] += (info[idx] + 1);
        DFS(ryan, n - info[idx] - 1, info, idx + 1);
        ryan[idx] -= (info[idx] + 1);
    }

    // 진행
    DFS(ryan, n, info, idx + 1);
    return;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11, 0); // 라이언 벡터

    DFS(ryan, n, info, 0);
    return answer;
}