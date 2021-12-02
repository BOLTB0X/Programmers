#include <string>
#include <vector>

using namespace std;

//���񰪹�ȯ
int abs(int a) {
    return a < 0 ? -a : a;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_hand = 10;
    int right_hand = 12;

    //�Ÿ�
    int l_dist = 0, r_dist = 0;

    //Ž��
    for (int i = 0; i < numbers.size(); ++i) {
        //������ ����ؾ� �� ���
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            //���� ��ü
            left_hand = numbers[i];
        }

        //�������� ����ؾ� �� ���
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            //������ ��ü
            right_hand = numbers[i];
        }

        //���
        else {
            //���Ǹ� ���� ��ü
            if (numbers[i] == 0) 
                numbers[i] = 11;

            //�Ÿ�
            l_dist = (abs(left_hand - numbers[i]) / 3) + (abs(left_hand - numbers[i]) % 3);
            r_dist = (abs(right_hand - numbers[i]) / 3) + (abs(right_hand - numbers[i]) % 3);

            if (l_dist > r_dist) {
                answer += 'R';
                //������ ��ü
                right_hand = numbers[i];
            }
            
            else if (l_dist < r_dist) {
                answer += 'L';
                //���� ��ü
                left_hand = numbers[i];
            }

            //�Ÿ��� ���� ���
            else {
                if (hand == "right") {
                    answer += "R";
                    right_hand = numbers[i];
                }

                else {
                    answer += "L";
                    left_hand = numbers[i];
                }
            }
        }
    }

    return answer;
}