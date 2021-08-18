#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp_arr;
    
    for (int i = 0; i < numbers.size(); i++) {
        tmp_arr.push_back(to_string(numbers[i]));
    }
    sort(tmp_arr.begin(), tmp_arr.end(), compare);
    for (int i = 0; i < tmp_arr.size(); i++) {
        answer += tmp_arr[i];
    }
    if (answer[0] == '0')
        return "0";
    return answer;
}