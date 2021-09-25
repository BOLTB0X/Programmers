#include <string>
#include <vector>

using namespace std;

int result = 51;

//최소
int min(int a, int b) {
    return a < b ? a : b;
}

//변환조건 다른 문자가 1개인지 판별
bool get_trans_cnt(string& begin, string& st) {
    int occ_cnt = 0;
    //문자열 특정 행, 열로 탐색
    for (int j = 0; j < st.length(); j++) {
        //시작단어와 탐색 단어와 차이 카운트
        if (begin[j] != st[j])
            occ_cnt++;
        //2개 이상이면 변환불가
        if (occ_cnt == 2)
            return false;
    }
    //다른 문자가 1개 이면
    return true;
}

//DFS정의
void DFS(string begin, string target, vector<string>& words, vector<bool>& visited, int cnt) {
    //탈출 조건
    if (begin == target) {
        result = min(result, cnt);
        return;
    }
    //문자열 비교
    for (int i = 0; i < words.size(); i++) {
        //변환조건이 되면
        if (get_trans_cnt(begin, words[i])) {
            //미방문 --> 즉 변환할수 있는 곳으로
            if (!visited[i]) {
                visited[i] = true;
                //이 해당 단어로 이동
                DFS(words[i], target, words, visited, cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    //방문벡터 생성 및 초기화
    vector<bool> visited(words.size(), false);
    //DFS로 탐색 시작
    DFS(begin, target, words, visited, 0);
    answer = result;
    if (answer == 51)
        return 0;
    return answer;
}