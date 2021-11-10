#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    //반복한 길이
    int number_size = number.size() - k;
    int start = 0;
    
    //완전탐색 스타일로
    for (int i = 0; i < number_size; i++) {
        //최대값 셋팅
        char max_number = number[start];
        int max_idx = start;
        
        //셋팅된 값 부터 k거리만큼 탐색
        for (int j = start; j <= k + i; j++) {
            if (max_number < number[j]) {
                max_number = number[j];
                max_idx = j;
            }
        }

        //탐색 후
        start = max_idx + 1;
        answer += max_number;
    }
    //정답 반환
    return answer;
}