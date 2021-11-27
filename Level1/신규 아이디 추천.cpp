#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = new_id;

    //1단계
    //소문자로 변환
    for (int i = 0; i < answer.length(); ++i) {
        //대문자 발견시
        if (answer[i] >= 'A' && answer[i] <= 'Z')
            //교체
            answer[i] = tolower(answer[i]);
    }

    //2단계
    //삭제
    for (int i = 0; i < answer.length();) {
        if ((answer[i] >= 'a' && answer[i] <= 'z') ||
            answer[i] == '-' || answer[i] == '_' ||
            answer[i] == '.' || (answer[i] >= '0' && answer[i] <= '9')) {
            i++;
            continue;
        }
        //삭제
        answer.erase(answer.begin() + i);
    }

    //3단계
    //치환
    for (int i = 1; i < answer.length(); ) {
        if (answer[i] == '.' && answer[i - 1] == '.') {
            answer.erase(answer.begin() + i);
            continue;
        }
        else 
            i++;
    }

    //4단계
    //제거
    if (answer.front() == '.') 
        answer.erase(answer.begin());
    if (answer.back() == '.') 
        answer.erase(answer.end() - 1);

    //5단계
    if (answer.length() == 0)
        answer = "a";

    //6단계
    //길이 조정
    if (answer.length() >= 16) {
        while (answer.length() != 15) {
            answer.erase(answer.begin() + 15);
        }
    }

    //만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 
    //끝에 위치한 마침표(.) 문자를 제거합니다.
    if (answer.back() == '.') 
        answer.erase(answer.end() - 1);

    //7단계
    if (answer.length() <= 2) {
        while (answer.length() != 3) {
            answer += answer.back();
        }
    }
    return answer;
}