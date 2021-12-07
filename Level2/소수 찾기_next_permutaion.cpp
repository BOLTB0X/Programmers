#include <string>
#include <vector>
#include <algorithm> // sort, next_permutaion

using namespace std;

//소수판별
bool is_primeNumber(int number) {
    if (number == 1 || number == 0)
        return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v;

    for (int i = 0; i < numbers.length(); ++i)
        v.push_back(numbers[i]);

    vector<int> per;
    sort(v.begin(), v.end());

    do {
        string tmp = "";
        for (int i = 0; i <= v.size(); ++i) {
            tmp += v[i];
            per.push_back(stoi(tmp));
        }
    } while (next_permutation(v.begin(), v.end()));
    sort(per.begin(), per.end());

    per.erase(unique(per.begin(), per.end()), per.end());

    for (int i = 0; i < per.size(); ++i) {
        if (is_primeNumber(per[i]))
            answer++;
    }

    return answer;
}