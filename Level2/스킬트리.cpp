#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    //스킬트리 행개수만큼 반복
    for (int i = 0; i < skill_trees.size(); i++) {
        //스킬트리의 행의 임시벡터
        vector<int> tmp_skill;
        for (int j = 0; j < skill_trees[i].size(); j++) {
            for (int k = 0; k < skill.length(); k++) {
                //스킬과 스킬트리가 같다면
                if (skill[k] == skill_trees[i][j])
                    tmp_skill.push_back(skill_trees[i][j]);
            }
        }
        bool flag = true;
        //스킬트리 순서가 맞는 지 체크
        for (int j = 0; j < tmp_skill.size(); j++) {
            if (skill[j] != tmp_skill[j]) {
                flag = false;
                break;
            }
        }
        if (flag)
            answer++;
    }
    return answer;
}
