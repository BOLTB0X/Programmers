#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string tmp = "";
vector<int> per;

//¼Ò¼öÆÇº°
bool is_primeNumber(int number) {
    if (number == 1 || number == 0)
        return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0)
            return false;
    }
    return true;
}

void DFS(string numbers, vector<bool>& visited, int depth) {
    if (depth == numbers.length())
        return;

    for (int i = 0; i < numbers.length(); ++i) {
        if (visited[i])
            continue;
        visited[i] = true;
        tmp.push_back(numbers[i]);
        per.push_back(stoi(tmp));
        DFS(numbers, visited, depth + 1);
        visited[i] = false;
        tmp.pop_back();
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> visited(numbers.length(), false);

    DFS(numbers, visited, 0);

    sort(per.begin(), per.end());
    per.erase(unique(per.begin(), per.end()), per.end());
    
    for (int i = 0; i < per.size(); ++i) {
        if (is_primeNumber(per[i]))
            answer++;
    }

    return answer;
}
