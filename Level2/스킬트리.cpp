#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    //Ʈ�� Ž��
    for (int i = 0; i < skill_trees.size(); i++) {
        vector<int> tmp;
        for (int j = 0; j < skill_trees[i].size(); j++) {
            //�� skill�� �ִ� �͵鸸 tmp�� ����
            for (int k = 0; k < skill.size(); k++) {
                if (skill[k] == skill_trees[i][j]) {
                    tmp.push_back(skill_trees[i][j]);
                }
            }
        }
        bool flag = true;
        //tmp�� skill�� ��
        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j] != skill[j]) {
                flag = false;
                break;
            }
        }
        //��ġ�ϸ� answer++
        if (flag)
            answer++;
    }
    return answer;
}