#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(const string a, const string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    int size = numbers.size();
    vector<string> tmp;
    
    for (int& number: numbers) {
        string n = to_string(number);
        tmp.push_back(n);
    }
    //정렬 기준 변경 후
    //내림차순 정렬
    sort(tmp.begin(),tmp.end(), compare);
    
    for (int i=0; i<tmp.size();++i) {
        answer += tmp[i];
    }
    if (answer[0] == '0')
        return "0";
    return answer;
}
