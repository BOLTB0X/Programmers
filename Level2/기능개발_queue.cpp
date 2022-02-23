#include <string>
#include <vector>

using namespace std;

int que[100];
int fr = 0, re = 0;

void enqueue(int data) {
    que[re++] = data;
    return;
}

void dequeue(void) {
    fr++;
    return;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = progresses.size();
    
    //큐에 삽입
    for (int i = 0; i < size; ++i)
        enqueue(i);
    
    //큐가 비어질때까지
    while (fr < re) {
        int cnt = 0; //배포 갯수
        
        //진도율 업데이트
        for (int i = 0; i < size; ++i) 
            progresses[i] += speeds[i];
        
        //큐가 비어있지 않고 진도율이 100이 되었다면
        while(fr < re && progresses[que[fr]] >= 100) {
            cnt++;
            dequeue();
        }
        if (cnt >= 1) //배포가 되었다면
            answer.push_back(cnt);
    }
    return answer;
}
