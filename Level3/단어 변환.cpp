#include <string>
#include <vector>

using namespace std;

//DFS를 사용하기에 전역 result
int result = 51;

//최소
int min(int a, int b) {
    return a<b?a:b;
}

//변환 체크
bool is_trans(string a, string b) {
    //두 문자열의 길이는 같으므로
    int cnt=0;
    for (int i=0;i<a.length();++i) {
        //다르므로 변환을 해야함
        if (a[i] != b[i])
            cnt++;
        //2번 변환은 안되므로
        if (cnt == 2)
            return false;
    }
    return true;
}

//깊이 우선 탐색
void DFS(vector<string> &words, vector<bool> &visited, string start, string target, int depth) {
    //탈출조건
    if (start == target) {
        result = min(result,depth);
        return;
    }
    
    //words벡터를 순회하며 변환가능한지 체크
    //가능하면 DFS호출
    for (int i=0;i<words.size();++i) {
        //변환 가능 여부 체크
        if (is_trans(words[i],start)) {
            //만약 재방문이면
            if (visited[i]) 
                continue;
            visited[i]=true;
            DFS(words,visited,words[i],target,depth+1);
            //각 케이스를 봐야하므로 미방문 처리
            visited[i]=false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    //방문리스트 생성 및 초기화
    vector<bool> visited(words.size(),false);
    //DFS호출
    DFS(words,visited,begin,target,0);
    
    //타겟을 찾았다면
    if (result != 51) 
        answer=result;
    
    //정답 반환
    return answer;
}
