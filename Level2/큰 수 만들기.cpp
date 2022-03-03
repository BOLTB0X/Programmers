#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.length();
    int start_idx = 0;
    
    //그리드 알고리즘
    //범위 셋팅 조심
    for (int i = 0; i < size - k; ++i) {
        int max_idx = start_idx;
        
        //현재 구간에서 최댓값 탐색
        for (int j = start_idx; j <= k + i; ++j) {
            if (number[max_idx] < number[j]) 
                max_idx = j;
        }
        
        //최댓값 셋팅 됐으므로
        start_idx = max_idx + 1; //찾은 최댓값 다음 부터 다시 시작
        answer += number[max_idx];
    }
    
    return answer;
}
