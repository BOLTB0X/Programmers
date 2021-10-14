#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//정렬조건 수정 즉 
//앞뒤로 더한 값이 큰거를 앞으로
bool compare(const string& a, const string& b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    //각 문자열을 정수로 변환하여 벡터에 삽입
    for (int i=0;i<numbers.size();++i) 
        v.push_back(to_string(numbers[i]));
    
    //정렬조건 수정 후 정렬
    sort(v.begin(),v.end(),compare);
   
    //v벡터가 정렬되었으므로 정답에 차례로 넣어준다.
    for (int i=0;i<v.size();++i)
        answer += v[i];
    
    //만약 맨 앞자리가 0이면
    if (answer[0] == '0')
        return "0";
    
    //정답 반환
    return answer;
}
