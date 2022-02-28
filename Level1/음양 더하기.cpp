#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    //순회
    for (int i=0;i<absolutes.size();i++) {
        if (signs[i]) //맞다면
            answer += absolutes[i];
        else //틀리다면
            answer -= absolutes[i];
    }
    return answer;
}
