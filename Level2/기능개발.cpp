#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> tmp_v ;
    vector<int> day;
    //�󸶳� ���Ҵ��� Ȯ��
    for (int i = 0; i < progresses.size(); i++) {
        tmp_v.push_back(100 - progresses[i]);
    }
    //���� �ɸ����� Ȯ��
    for (int i = 0; i < tmp_v.size(); i++) {
        if (tmp_v[i] % speeds[i] == 0) {
            day.push_back(tmp_v[i] / speeds[i]);
        }
        else 
            day.push_back((tmp_v[i] / speeds[i])+1);
    }
    int sample_day = day[0];
    int cnt = 1;
    //�� �Ⱓ�� ���� �����Ǵ��� Ȯ��
    for (int i = 1; i < day.size(); i++) {
        if (sample_day >= day[i]) 
            cnt += 1;
        else {
            answer.push_back(cnt);
            sample_day = day[i];
            cnt = 1;
        }
    }
    //�������� ������ �ȵǴ�
    answer.push_back(cnt);

    return answer;
}