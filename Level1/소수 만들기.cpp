#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool is_prime_number(int n) {
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i < (int)(sqrt(n) + 1); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int tmp_number = nums[i] + nums[j] + nums[k];
                if (is_prime_number(tmp_number) == true)
                    answer++;
            }
        }
    }
    return answer;
}