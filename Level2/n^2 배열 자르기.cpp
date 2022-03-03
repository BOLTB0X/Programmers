#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    //��Ģ �̿�
    for (long long i = left; i <= right; ++i) {
        int row = i / n;
        int col = i % n;

        int ele = row > col ? row + 1 : col + 1;
        answer.push_back(ele);
    }
    return answer;
}