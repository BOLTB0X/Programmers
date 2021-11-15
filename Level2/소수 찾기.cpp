#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//소수판별
bool is_prime(int n) {
    if (n == 1 || n == 0)
        return false;

    for (int i = 2; i * i <= n; ++i) 
        if (n % i == 0)
            return false;

    return true;
}

int solution(string numbers) {
    int answer = 0;
    //조합을 위한 벡터
    vector<char> v;

    //문자열 벡터에 삽입
    for (int i = 0; i < numbers.length(); ++i)
        v.push_back(numbers[i]);

    //순열을 위한 오름차순 정렬
    sort(v.begin(), v.end());

    //다음순열 알고리즘을 이용하여 소수를 탐색
    vector<int> per;
    do {
        string tmp = "";
        for (int i = 0; i < v.size(); ++i) {
            tmp += v[i];
            per.push_back(stoi(tmp));
        }
    } while (next_permutation(v.begin(), v.end()));

    //순열 벡터 정렬
    sort(per.begin(), per.end());

    //중복 제거
    per.erase(unique(per.begin(), per.end()), per.end());

    //순열들 중 소수 탐색
    for (int i = 0; i < per.size(); ++i) 
        if (is_prime(per[i]))
            answer++;

    //반환
    return answer;
}
