#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    int size = a.size(); //내적 조건상 b랑 같음
    
    //내적 연산
    for (int i = 0; i < size ;i++) 
        answer += (a[i] * b[i]);
    
    return answer;
}
