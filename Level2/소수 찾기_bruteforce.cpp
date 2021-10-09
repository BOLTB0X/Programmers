#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;

//소수판별
bool is_prime(int num) {
    if (num == 1 || num == 0)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int str_len = numbers.length();
    vector<char> v;

    //문자형 벡터에 삽입
    for (int i = 0; i < str_len; ++i)
        v.push_back(numbers[i]);

    //순열 전 정렬
    sort(v.begin(), v.end());
    vector<int> per;
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

    //마지막 만들어진 per의 소수인지 판단
    for (int i = 0; i < per.size(); ++i) {
        if (is_prime(per[i]))
            answer++;
    }
    return answer;
}
