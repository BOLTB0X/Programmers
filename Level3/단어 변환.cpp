#include <string>
#include <vector>

using namespace std;

//결과
int result = 51;

//최소
int min(int a, int b) {
    return a < b ? a : b;
}

bool is_trans(string &a, string &b) {
    //각 문자열의 길이는 같으므로
    int trans_cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i])
            trans_cnt++;
        //두 번 변환해야하면 
        if (trans_cnt == 2)
            return false;
    }
    return true;
}

//깊이 우선
void DFS(string start, string target, vector<string>& words, vector<bool>& visited, int depth) {
    //탈출 조건
    if (start == target) {
        result = min(result, depth);
        return;
    }

    //각 단어벡터 순회
    for (int i = 0; i < words.size(); i++) {
        //변환가능한지
        if (is_trans(start, words[i])) {
            //재방문이면
            if (visited[i])
                continue;
            //방문체크
            visited[i] = true;
            //DFS호출
            DFS(words[i], target, words, visited, depth + 1);
            //완전탐색이므로 다시 미방문 처리
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    //먼저 체크리스트 초기화
    vector<bool> visited(words.size(), false);
    
    //DFS호출
    DFS(begin, target, words, visited, 0);
    
    //결과 변수 값 체크
    if (result == 51)
        answer = 0;
    else
        answer = result;
    
    //정답 반환
    return answer;
}
