#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sum(vector<int>& v) {
    int tot = 0;
    for (int i = 0; i < v.size(); ++i)
        tot += v[i];

    return tot;
}

int solution(vector<int> d, int budget) {
    int answer = 0;

    //오름차순 정렬
    sort(d.begin(), d.end());

    while (budget < sum(d))
        d.pop_back();

    answer = d.size();
    return answer;
}