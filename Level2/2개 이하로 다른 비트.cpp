#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    long long size = numbers.size();
    
    for (long long& number: numbers) {
        if (number % 2 == 0)
            answer.push_back(number + 1);
        else {
            long long bit = 1;
            // 가장 오른쪽부터 차례로 n 개의 연속된 1 로 이루어진 비트구하기
            while (1) {
                if ((numbers[i] & bit) == 0) break;
                bit *= 2; // 곱하기 2 를 하면 다음 비트로
            }
            bit /= 2;

            // 구한 비트 더해주기
            answer.push_back(numbers[i] + bit);
        }
    }
    return answer;
}
