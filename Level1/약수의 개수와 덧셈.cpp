#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    vector<int> arr;
    for (int i = left; i <= right; ++i)
        arr.push_back(i);

    for (int i = 0; i < arr.size(); ++i) {
        int cnt = 0;
        //각 약수 갯수 확인
        for (int j = 1; j <= arr[i]; ++j) {
            if (arr[i] % j == 0)
                cnt++;
        }
        if (cnt % 2 == 0)
            answer += arr[i];
        else
            answer -= arr[i];
    }

    return answer;
}