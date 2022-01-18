#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    //3진법연산
    //단 1,2,4 이므로 0,1,2에서 0일때 몫-1해줘야함
    while (n > 0) {
        int r = n % 3;
        n /= 3;
        if (r == 0) {
            answer = "4" + answer;
            n--;
        }
        else if (r == 1)
            answer = "1" + answer;
        else if (r == 2)
            answer = "2" + answer;
    }
    return answer;
}
