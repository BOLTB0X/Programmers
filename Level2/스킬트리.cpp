#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    //트리 탐색
    for (int i = 0; i < skill_trees.size(); i++) {
        vector<int> tmp;
        for (int j = 0; j < skill_trees[i].size(); j++) {
            //즉 skill에 있는 것들만 tmp에 삽입
            for (int k = 0; k < skill.size(); k++) {
                if (skill[k] == skill_trees[i][j]) {
                    tmp.push_back(skill_trees[i][j]);
                }
            }
        }
        bool flag = true;
        //tmp와 skill이 비교
        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j] != skill[j]) {
                flag = false;
                break;
            }
        }
        //일치하면 answer++
        if (flag)
            answer++;
    }
    return answer;
}