#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for (int r = 0; r < arr1.size(); r++) {
        vector<int> tmp;
        for (int c = 0; c < arr2[0].size(); c++) {
            int value = arr1[r][c] + arr2[r][c];
            tmp.push_back(value);
        }
        answer.push_back(tmp);
    }
    return answer;
}