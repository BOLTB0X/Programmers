#include <string>
#include <vector>
#include <map>
#include <sstream> // ���ǿ�
#include <cmath>

using namespace std;

int get_minues(string start, string end) {
    int minues = 0;

    int sh = stoi(start.substr(0, 2));
    int sm = stoi(start.substr(3, 2));
    int eh = stoi(end.substr(0, 2));
    int em = stoi(end.substr(3, 2));

    minues = (eh - sh) * 60 + (em - sm);

    return minues;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> dict; // ���ǿ�

    stringstream ss;
    for (string& record : records) {
        ss.str(record); // �����
        string time, car_number, cmd;
        ss >> time >> car_number >> cmd;

        dict[car_number].push_back(time); // ��ųʸ��� �ܾ� ����
        ss.clear();
    }

    //��ųʸ��� ���������� Ȯ��
    for (auto& it : dict) {
        // Ȧ���� ���
        if (it.second.size() & 1)
            it.second.push_back("23:59");

        vector<string> dict_v = it.second;
        int tot = 0;
        // �� �ð� ���
        for (int i = 0; i < dict_v.size() - 1; i += 2)
            tot += get_minues(dict_v[i], dict_v[i + 1]);

        int fee = fees[1]; // �⺻ ���
        // �ʰ��ݾ� �߻�
        if (tot > fees[0])
            fee += ceil((tot - fees[0]) / (double)fees[2]) * fees[3];
        answer.push_back(fee);
    }
    return answer;
}