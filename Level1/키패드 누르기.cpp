#include <string>
#include <vector>

using namespace std;

//절댓값반환
int abs(int a) {
    return a < 0 ? -a : a;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_hand = 10;
    int right_hand = 12;

    //거리
    int l_dist = 0, r_dist = 0;

    //탐색
    for (int i = 0; i < numbers.size(); ++i) {
        //왼쪽을 사용해야 할 경우
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            //왼쪽 교체
            left_hand = numbers[i];
        }

        //오른쪽을 사용해야 할 경우
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            //오른쪽 교체
            right_hand = numbers[i];
        }

        //가운데
        else {
            //편의를 위해 교체
            if (numbers[i] == 0) 
                numbers[i] = 11;

            //거리
            l_dist = (abs(left_hand - numbers[i]) / 3) + (abs(left_hand - numbers[i]) % 3);
            r_dist = (abs(right_hand - numbers[i]) / 3) + (abs(right_hand - numbers[i]) % 3);

            if (l_dist > r_dist) {
                answer += 'R';
                //오른쪽 교체
                right_hand = numbers[i];
            }
            
            else if (l_dist < r_dist) {
                answer += 'L';
                //왼쪽 교체
                left_hand = numbers[i];
            }

            //거리가 같은 경우
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