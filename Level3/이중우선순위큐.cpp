#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    //덱 선언
    deque<int> dq;
    
    //각 연산자벡터 순회
    for (int i=0;i<operations.size();++i) {
        //각 명령어 문자열은 항상 첫번째가 명령어이므로
        string operation = operations[i].substr(0,1);
        //1은 공백 그 이후 숫자정보이므로
        //형 변환
        int number = stoi(operations[i].substr(2));
        
        //이제 연산자 종류로 덱에 원소 삽입인지 삭제인지 판단
        
        //삽입이면
        if (operation == "I") {
            dq.push_back(number);
            //원소가 삽입되면 오름차순 정렬
            sort(dq.begin(),dq.end());
        }
        //삭제면
        else if (operation == "D") {
            //덱이 비어있다면
            if (dq.empty())
                continue;
            //최솟값 삭제
            //즉 덱의 앞 원소
            if (number == -1) 
                dq.pop_front();
            //최댓값 삭제
            //즉 덱의 가장 뒤
            else if (number == 1)
                dq.pop_back();
        }
    }
    
    //만약 덱이 비어있다면
    if (dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    //비어있지 않다면
    else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    //정답 반환
    return answer;
}
