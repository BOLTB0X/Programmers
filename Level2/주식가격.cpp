#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int size = prices.size();

    for (int i = 0; i < size; ++i) {
        int cmp = prices[i];
        int sec = 0;
        for (int j = i + 1; j < size; ++j) {
            sec++;
            if (cmp > prices[j])
                break;
        }
        answer.push_back(sec);
    }
    return answer;
}