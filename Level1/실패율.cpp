#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int num = stages.size();
    //각 플레이어의 스테이지 실패율
    map<int, int> dict;
    //실패율
    vector<pair<int, double>> fails;

    //스테이지 실패율을 체크
    //만약 KEY값이 N을 넘는 경우는 올 클리어를 했다는 뜻
    //실패율 구할 때 고려 X
    for (int i = 0; i < num; ++i)
        dict[stages[i]]++;

    for (int i = 1; i <= N; ++i) {
        //도달한 유저가 없는 경우는 실패율을 0으로 취급
        if (dict[i] == 0) {
            fails.push_back({ i, 0 });
            continue;
        }
        fails.push_back({ i, (double)dict[i] / num });
        num -= dict[i];
    }
    //실패율 기준으로 내림차순 정렬
    sort(fails.begin(), fails.end(), compare);

    //스테이지만 정답벡터에 삽입
    for (int i = 0; i < N; ++i)
        answer.push_back(fails[i].first);
    return answer;
}