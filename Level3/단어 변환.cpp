#include <string>
#include <vector>

using namespace std;

int result = 51;

// 최솟값반환
int Min(int a, int b) {
    return a < b ? a : b;
}

// 단어 차이 확인
int is_trans(string a, string b) {
    int cnt = 0;
    for (int i=0;i<a.length();++i) {
        if (a[i] != b[i])
            cnt++;
        if (cnt == 2)
            return 0;
    }
    return 1;
}

void DFS(vector<string> &words, vector<int> &visited, string cur, string target, int level) {
    // 목표에 도달 했다면
    if (cur == target) {
        result = Min(result,level);
        return;
    }
    
    for (int i = 0; i < words.size(); ++i) {
        // 반환이 가능하다면
        if (is_trans(cur,words[i]) == 1) {
            if (visited[i] == 1)
                continue;
            visited[i] = 1;
            DFS(words,visited,words[i],target,level+1);
            visited[i] = 0;
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<int> visited(words.size(),0); // 방문리스트 초기화
    
    DFS(words, visited, begin, target, 0);
    
    if (result != 51) 
        answer = result;
    return answer;
}
