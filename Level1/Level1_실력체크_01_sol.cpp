#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string str = to_string(x);
    int tot = 0;

    for (int i = 0; i < str.length(); ++i)
        tot += (str[i] - '0');

    if (x % tot != 0)
        answer = false;
    return answer;
}