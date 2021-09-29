#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    if (n == 1 || n == 0)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v;
    //문자열 원소를 벡터에 삽입
    for (int i = 0; i < numbers.size(); i++)
        v.push_back(numbers[i]);

    //벡터 오름차순 정렬
    sort(v.begin(), v.end());

    //v벡터로 만들 수 있는 경의 수를 담을 벡터
    vector<int> per;
    //경우의 수 탐색 시작
    do {
        string tmp = "";
        for (int i = 0; i <= v.size(); i++) {
            //만들 수 있는 모든 수를 per에 삽입
            tmp.push_back(v[i]);
            per.push_back(stoi(tmp));
        }
    } while (next_permutation(v.begin(), v.end()));
    //순열 벡터 정렬
    sort(per.begin(), per.end());
    //중복값 제거 
    per.erase(unique(per.begin(), per.end()), per.end());

    for (int i = 0; i < per.size(); i++) {
        if (is_prime(per[i])) {
            answer++;
        }
    }
    return answer;
}
