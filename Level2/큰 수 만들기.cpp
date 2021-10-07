#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    //�ݺ��� ����
    int number_size = number.size() - k;
    int start = 0;
    //����Ž�� ��Ÿ�Ϸ�
    for (int i = 0; i < number_size; i++) {
        //�ִ밪 ����
        char max_number = number[start];
        int max_idx = start;
        //���õ� �� ���� k�Ÿ���ŭ Ž��
        for (int j = start; j <= k + i; j++) {
            if (max_number < number[j]) {
                max_number = number[j];
                max_idx = j;
            }
        }
        //Ž�� ��
        start = max_idx + 1;
        answer += max_number;
    }
    //���� ��ȯ
    return answer;
}