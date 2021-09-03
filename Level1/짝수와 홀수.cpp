#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    if ((int)num % 2 == 0)
        answer = "Even";
    else if ((int)num % 2 != 0)
        answer = "Odd";
    return answer;
}