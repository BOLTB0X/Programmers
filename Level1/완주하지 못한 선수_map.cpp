#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //맵으로 해쉬처럼 사용
    unordered_map <string, int> hash;
    //참여한 사람을 모두 1
    for (string name : participant)
        hash[name]++;
    //이제 완주한 사람들 -1;
    for (string name : completion)
        hash[name]--;
    //이제 아직도 value가 1이면 그 key가 완주하지 못한 선수
    for (string name : participant) {
        if (hash[name] == 1)
            answer = name;
    }
    return answer;
}