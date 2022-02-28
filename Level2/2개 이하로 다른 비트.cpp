#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    long long size = numbers.size();

    for (long long& number : numbers) {
        if (number % 2 == 0)
            answer.push_back(number + 1);
        else {
            long long last_Zero = (number + 1) & (-number);
            long long result = (number | last_Zero) & (~(last_Zero >> 1));
            answer.push_back(result);
        }
    }
    return answer;
}