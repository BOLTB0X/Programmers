#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int tmp;

//���� ���� ����
bool compare(string a, string b) {
    if (a[tmp] != b[tmp])
        return a[tmp] < b[tmp];
    else
        return a < b;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    tmp = n;
    //���� ���� ���� 
    sort(strings.begin(), strings.end(), compare);

    //���交�Ϳ� ����
    for (int i = 0; i < strings.size(); ++i)
        answer.push_back(strings[i]);

    return answer;
}