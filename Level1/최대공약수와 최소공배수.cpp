#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int gcd_value = gcd(n, m);
    int lcm_value = (n * m) / gcd(n, m);
    answer.push_back(gcd_value);
    answer.push_back(lcm_value);
    return answer;
}