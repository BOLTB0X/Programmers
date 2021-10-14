#include <string>
#include <vector>

using namespace std;

int result = 9;

//최솟값 비교
int min(int a, int b) {
    return a < b ? a : b;
}

//깊이 우선 탐색
void DFS(int n, int number, int tot, int depth) {
    //8보다 크면 안되므로
    if (depth >= 9)
        return;
    //만들어진 값이 타겟과 같아지면
    if (tot == number) {
        result = min(result, depth);
        return;
    }
    int r = 0;
    //최대 반복 횟수만큼 반복
     //n부터 nn,nnn,nnn ..
    //n 뒤 연산자 붙이고 nn 뒤에 붙이고 반복
    for (int i = 0; i + depth < 9; ++i) {
        r = r * 10 + n;
        DFS(n, number, tot + r, depth + 1 + i);
        DFS(n, number, tot - r, depth + 1 + i);
        DFS(n, number, tot * r, depth + 1 + i);
        DFS(n, number, (int)tot / r, depth + 1 + i);
    }
}

int solution(int N, int number) {
    int answer = 0;

    //DFS
    DFS(N, number, 0, 0);

    //8보다 크면
    if (result > 8)
        answer = -1;
    else
        answer = result;
    return answer;
}