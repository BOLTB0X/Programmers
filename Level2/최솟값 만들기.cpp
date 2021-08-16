#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int swap(int* a, int* b) {
    int* tmp = a;
    a = b;
    b = tmp;
}
/*
void sort(vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
        int min_idx = i;
        for (int j = i + 1; j < A.size(); j++) {
            if (A[min_idx] > A[j]) {
                min_idx = j;
            }
        }
        swap(A[min_idx], A[i]);
    }
}
*/
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    for (int i = 0; i < A.size(); i++) {
        answer += (A[i] * B[A.size()-1-i]);
    }
    return answer;
}