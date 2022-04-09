#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.length(); // 길이
    
    // 탐색 시작
    int start_idx= 0; // 시작 인덱스 설정
    // 총 2개를 지우고 만들 수 있는 수 
    for (int i = 0; i < size - k; ++i) {
        int max_idx = start_idx; // 최댓값을 알기위해 시작점으로
        // 그리디로 큰 값 체크
        for (int j = start_idx; j <= k + i; ++j) {            
            if (number[max_idx] - '0' < number[j] - '0')
                max_idx = j;
        }
        
        // 시작 위치를 현재 최댓값 뒤로 셋팅
        start_idx = max_idx + 1;
        answer += number[max_idx];
    }
    return answer;
}
