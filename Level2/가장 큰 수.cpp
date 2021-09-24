#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    //벡터 탐색
    //문자열로 변환하여 벡터에 삽입
    for (int i = 0; i < numbers.size(); i++) {
        v.push_back(to_string(numbers[i]));
    }
    //정렬조건 수정후 정렬
    sort(v.begin(), v.end(), compare);

    //순차적으로 문자열 answer에 더해줌
    for (int i = 0; i < v.size(); i++) {
        answer += v[i];
    }
    //첫번째 자리가 0일수도 있으므로
    if (answer[0] == '0')
        return "0";
    return answer;
}
