#include <string>
#include <vector>
#include <algorithm> // sort

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h_idx = citations.size();
    // h번 이상 나머지 논문은 h번이하 인용
    // 즉 인덱스를 길이로 할당하고 
    // 순차적으로 줄여가며 작거나 같아지는 지점이 정답
    
    // 오름차순 정렬
    sort(citations.begin(), citations.end());
    
    // 탐색
    for (int i = 0; i < citations.size(); ++i) {
        if (h_idx <= citations[i]) 
            break;
        h_idx--;
    }
    
    answer = h_idx;
    return answer;
}
