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
    
    for (int i =0; i < size; ++i)
        enqueue(i);
    
    while (fr < re) {
        int cnt = 0;
        
        // 진도율
        for (int i = 0; i < size; ++i)
            progresses[i] += speeds[i];
        
        while(fr < re && progresses[que[fr]] >= 100) {
            cnt++; // 카운트
            dequeue();
        }
        if (cnt != 0)
            answer.push_back(cnt);
    }
    return answer;
}
