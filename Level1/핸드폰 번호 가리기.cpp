#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    string tmp = "";
    int cnt = 0;
    
    //�Ųٷ� Ž��
    for (int i = phone_number.length() - 1; i >= 0; --i) {
        if (cnt < 4) {
            tmp += phone_number[i];
            cnt++;
        }
        else
            tmp += '*';
    }

    //�ٽ� �Ųٷ�
    for (int i = tmp.length() - 1; i >= 0; --i)
        answer += tmp[i];

    //��ȯ
    return answer;
}