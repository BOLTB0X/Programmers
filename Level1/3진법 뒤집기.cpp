#include <string>
#include <vector>

using namespace std;

//3진법 변환
string get_ter(int n) {
    string tmp = "";
    
    while (n > 0) {
        int mod = n % 3;
        tmp += (char)(mod + '0');
        n /= 3;
    }
    //이 연산으로 뒤집어서 나옴
    return tmp;
}

//10진법 변환
int get_dec(string ter) {
    int tot = 0;
    int size = ter.size();
    
    for (int i = size - 1, j = 1; i>=0; --i, j *= 3)
        tot += j * (ter[i] - '0');
    
    return tot;
}

int solution(int n) {
    int answer = 0;
    answer = get_dec(get_ter(n));
    return answer;
}
