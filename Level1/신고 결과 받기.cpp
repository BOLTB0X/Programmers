#include <iostream>
#include <string>
#include <vector>

using namespace std;

int score[1000][1000];
int sum[1000];

void init(int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j)
            score[i][j] = 0;
    }
    for (int i = 0; i < len; ++i)
        sum[i] = 0;
    return;
}

vector<string> get_split(string report) {
    vector<string> v;
    int pos = report.rfind(' ');

    v.push_back(report.substr(0, pos));
    v.push_back(report.substr(pos + 1));

    return v;
}

void count_score(vector<string>& id_list, vector<string>& st) {
    int row = 0, col = 0;
    for (int i = 0; i < id_list.size(); ++i) {
        if (id_list[i] == st[0])
            row = i;
        else if (id_list[i] == st[1])
            col = i;
    }

    //중복신고 방지
    if (score[row][col] == 0) {
        score[row][col]++;
        sum[col]++;
    }

    return;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    //편의용
    int len = id_list.size();
    //초기화
    init(len);

    for (int i = 0; i < report.size(); ++i) {
        vector<string> str = get_split(report[i]);
        count_score(id_list, str);
    }

    for (int i = 0; i < len; ++i) {
        int cnt = 0;
        for (int j = 0; j < len; ++j) {
            //신고 1번하고 누적횟수 조건 확인
            if (score[i][j] > 0 && sum[j] >= k) 
                cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}


int main(void) {
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };

    vector<int> ret = solution(id_list, report, 2);

    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << ' ';
    }
}
