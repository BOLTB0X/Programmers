#include <string>
#include <vector>

using namespace std;

//결과
int result = 51;

//최소
int min(int a, int b) {
    return a<b?a:b;
}

//단어 체크
bool is_trans(string &str1, string &str2) {
    int cnt=0;
    //글자수는 같으므로
    for (int i=0;i<str1.size();++i) {
        //다를 경우 카운트
        if (str1[i] != str2[i]) {
            cnt++;
        }
        //2개부터는 안되므로 거짓 반환
        if (cnt == 2)
            return false;
    }
    return true;
}

//깊이 우선
void DFS(vector<string> &words, vector<bool> &visited, string start, string target, int depth) {
    //도달 한다면
    if (start == target) {
        //최소값 셋팅
        result = min(result,depth);
        return;
    }
    //탐색
    for (int i=0;i<words.size();++i) {
        //만약 변환이 가능하다면
        if (is_trans(start,words[i])) {
            //방문 한 경우 예외
            if (visited[i])
                continue;
            //방문처리
            visited[i]=true;
            DFS(words,visited,words[i],target,depth+1);
            visited[i]=false;
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    //방문리스트 생성 및 초기화
    vector<bool> visited(words.size(),false);
    
    //DFS로 탐색 시작
    DFS(words,visited,begin,target,0);

    //변환 못하던 하던 타겟에 도달하지 못하면
    if (result == 51)
        answer = 0;
    else
        answer=result;
    return answer;
}
