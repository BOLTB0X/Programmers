#include <string>
#include <vector>
#define Max_Size 10000001 // 최대 길이

using namespace std;

vector<int> prime;
int check[Max_Size] = {0,}; //소수 체크를 위한 배열

//에라토스테네체
void eratos(void) {
    check[0] = check[1] = 1;
    
    for (int i = 2; i * i < Max_Size; ++i) {
        if (check[i] == 1)
            continue;
        for (int j = i + i; j < Max_Size; j += i)
            check[j] = 1;
    }
    return;
}

//문자열 -> int형으로 변환
int trans_int(string str) {
    int res = 0;
    //문자열이므로 역순으로
    for (int i = str.length() - 1, j = 1; i >= 0; --i, j *= 10)
        res += j * (str[i] - '0');
    return res;
}

//중복방지용 -> vector 유니크도 이용가능
int in_prime_vector(int n) {
    for (int&p : prime) {
        if (p == n)
            return 1;
    }
    
    return 0;
}

//백트래킹을 이용한 경우의 수
void DFS(string numbers, string number, vector<int>& visited, int size) {
    //탈출조건 -> 현재 만들어진 number의 길이가 제한 size와 같다면
    if (number.length() == size) {
        int n = trans_int(number); //변환, atoi도 가능
        //해당수가 소수이고 이미 벡터에 삽입되있지 않다면
        if (check[n] == 0 && in_prime_vector(n) == 0)  
            prime.push_back(n);
        return;
    }
    
    //각 문자열 내 원소들로 순회시작
    for (int i = 0; i < numbers.length(); ++i) {
        //재방문인 경우 -> 중복 허용 X
        if (visited[i] == 1)
            continue;
        
        visited[i] = 1;
        number.push_back(numbers[i]);
        DFS(numbers, number, visited, size); //탐색
        visited[i] = 0;
        number.pop_back();
    }
    return;
}

int solution(string numbers) {
    int answer = 0;
    int size = numbers.length(); //길이
    vector<int> visited(size, 0);
    eratos(); //먼저 소수 체크
    
    //1부터 사이즈까지 순차적으로 나올 수 있는 수 경우의 수를 확인
    for (int i = 1; i <= size; ++i) {
        string tmp = "";
        DFS(numbers, tmp, visited, i);
    }
    
    answer = prime.size(); //길이가 곧 갯수
    return answer;
}
