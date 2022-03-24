#include <string>
#include <vector>
#include <algorithm> // sort

using namespace std;

int compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for (int& num: numbers) 
        v.push_back(to_string(num));
    
    // 정렬
    sort(v.begin(), v.end(), compare);
    for (string &i: v)
        answer += i;
    
    // 첫 번째 자리가 0이면
    if (answer[0] == '0')
        answer = "0";
        
    return answer;
}
