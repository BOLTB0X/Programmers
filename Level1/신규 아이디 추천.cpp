#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = new_id;

    //1�ܰ�
    //�ҹ��ڷ� ��ȯ
    for (int i = 0; i < answer.length(); ++i) {
        //�빮�� �߽߰�
        if (answer[i] >= 'A' && answer[i] <= 'Z')
            //��ü
            answer[i] = tolower(answer[i]);
    }

    //2�ܰ�
    //����
    for (int i = 0; i < answer.length();) {
        if ((answer[i] >= 'a' && answer[i] <= 'z') ||
            answer[i] == '-' || answer[i] == '_' ||
            answer[i] == '.' || (answer[i] >= '0' && answer[i] <= '9')) {
            i++;
            continue;
        }
        //����
        answer.erase(answer.begin() + i);
    }

    //3�ܰ�
    //ġȯ
    for (int i = 1; i < answer.length(); ) {
        if (answer[i] == '.' && answer[i - 1] == '.') {
            answer.erase(answer.begin() + i);
            continue;
        }
        else 
            i++;
    }

    //4�ܰ�
    //����
    if (answer.front() == '.') 
        answer.erase(answer.begin());
    if (answer.back() == '.') 
        answer.erase(answer.end() - 1);

    //5�ܰ�
    if (answer.length() == 0)
        answer = "a";

    //6�ܰ�
    //���� ����
    if (answer.length() >= 16) {
        while (answer.length() != 15) {
            answer.erase(answer.begin() + 15);
        }
    }

    //���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� 
    //���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
    if (answer.back() == '.') 
        answer.erase(answer.end() - 1);

    //7�ܰ�
    if (answer.length() <= 2) {
        while (answer.length() != 3) {
            answer += answer.back();
        }
    }
    return answer;
}