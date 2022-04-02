#include <string>
#include <vector>

using namespace std;

int result = 51; // 최소를 위한
vector<int> visited; // 방문리스트

// 최솟값 반환
int Min(int a, int b) {
    return a < b ? a : b;
}

// 1개만 차이가 나는지
bool is_trans_condi(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i])
            cnt++;
    }
    
    return cnt == 1 ? 1 : 0;
}

// 깊이우선탐색
void DFS(vector<string>& words, int size, string cur, string target, int level) {
    // 탈출 조건
    if (cur == target) {
        result = Min(result, level);
        return;
    }
        
    for (int i = 0; i < size;++i) {
        // 조건
        if (is_trans_condi(cur, words[i]) == 1) {                  
            if (visited[i] == 1) // 재방문 방지
                continue;
        
            visited[i] = 1;
            DFS(words, size, words[i], target, level + 1);
            visited[i] = 0;
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int size = words.size(); // 길이
    visited.resize(size, 0); // 초기화
    
    DFS(words, size, begin, target, 0);
    // 도달 가능하다면
    if (result != 51)
        answer = result;
    return answer;
}
