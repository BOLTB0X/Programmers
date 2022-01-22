#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();

    //문자열 탐색
    //문자열 압축이므로 n/2만큼 만 쪼개야함
    for (int i = 1; i <= s.length() / 2; i++) {
        //임시와 압축
        string tmp = "", convert = "";

        int cnt = 1;
        //substr로 i씩 잘라봄
        tmp = s.substr(0, i);
        
        //i씩 반복되는게 몇개인지 차례로 확인
        for (int j = i; j < s.length(); j += i) {
            if (tmp == s.substr(j, i))
                cnt++;
            else {
                //2 이상이면
                if (cnt > 1)
                    convert += to_string(cnt);
                convert += tmp;
                //반복되는 것을 바꿔야 하므로
                tmp = s.substr(j, i);
                //초기화
                cnt = 1;
            }
        }
        //2 이상이면
        if (cnt > 1)
            convert += to_string(cnt);
        convert += tmp;

        //길이가 작은 값으로 변경
        answer = answer < convert.length() ? answer : convert.length();
    }

    //반환
    return answer;
}
