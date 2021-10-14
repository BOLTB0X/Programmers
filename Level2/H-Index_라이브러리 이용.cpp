#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    //오름차순 정렬
    sort(citations.begin(), citations.end());

    //H-index를 찾기 위해 먼저 논몬벡터의 길이로 초기화
    //문제에서  n편 중, h번 이상 인용된 논문이 h편 이상이고 
    //나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 H-Index
    //즉 오름차순 정렬을 하여 해당 idx와 크거나 같은 경우를 찾으면 됌
    //탐색
    for (int i = 0; i < citations.size(); ++i) {
        int h_idx = citations.size() - i;
        if (h_idx <= citations[i]) {
            //찾으면 무조건 브레이크
            //해주지 않으면 계속 작아진다.
            answer = h_idx;
            break;
        }
    }
    //정답 반환
    return answer;
}