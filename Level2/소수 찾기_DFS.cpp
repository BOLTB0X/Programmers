#include <string>
#include <vector>

using namespace std;

vector<int> per;
int check[10000000] = { 0, };

//에라토스테네체
void eratos(void) {
    check[0] = check[1] = 1;
    for (int i = 2; i * i < 10000000; ++i) {
        if (check[i] == 1) //이미 소수가 아니라면
            continue;
        for (int j = i + i; j < 10000000; j += i)
            check[j] = 1;
    }
    return;
}

//정수로 변환
int get_dec(string str) {
    int res = 0;
    for (int i = str.length() - 1, j = 1; i >= 0; --i, j *= 10)
        res += j * (str[i] - '0');
    return res;
}

//중복 방지
int is_in_per(int number) {
    for (int& p : per) {
        if (p == number)
            return 0;
    }
    return 1;
}

//백트래킹
void DFS(string numbers, vector<bool>& visited, string tmp, int size) {
    //탈출 조건
    if (tmp.length() == size) {
        //int number = stoi(tmp); //정수로 변환
        int number = get_dec(tmp);
        if (check[number] == 0 && is_in_per(number))
            per.push_back(number);
        return;
    }

    for (int i = 0; i < numbers.length(); ++i) {
        if (visited[i] == 1)
            continue;
        visited[i] = 1;
        tmp.push_back(numbers[i]);
        DFS(numbers, visited, tmp, size);
        tmp.pop_back();
        visited[i] = 0;
    }
    return;
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> visited(numbers.length(), false);

    eratos(); //소수 제거
    for (int i = 1; i <= numbers.length(); ++i) {
        string tmp = "";
        DFS(numbers, visited, tmp, i);
    }

    //per벡터사이즈가 곧 갯수
    answer = per.size();

    return answer;
}
