#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //������ �ؽ�ó�� ���
    unordered_map <string, int> hash;
    //������ ����� ��� 1
    for (string name : participant)
        hash[name]++;
    //���� ������ ����� -1;
    for (string name : completion)
        hash[name]--;
    //���� ������ value�� 1�̸� �� key�� �������� ���� ����
    for (string name : participant) {
        if (hash[name] == 1)
            answer = name;
    }
    return answer;
}