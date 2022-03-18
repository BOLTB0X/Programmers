#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ���� �Լ�
vector<vector<int>> remove_answer(vector<vector<int>>& answer, int x, int y, int a) {
    // �ӽ�
    vector<vector<int>> tmp;

    // Ž��
    for (vector<int>& ans : answer) {
        // ������ Ÿ���� �ִٸ�
        if (ans[0] == x && ans[1] == y && ans[2] == a)
            continue;

        // ����
        tmp.push_back(ans);
    }

    return tmp;
}

//�������� üũ
int is_possible(vector<vector<int>>& answer) {
    for (vector<int>& ans : answer) {
        int x = ans[0];
        int y = ans[1];
        int a = ans[2]; // ������ 0 -> ���, 1 -> ��

        // ����� �ٴ� ���� �ְų� ���� ���� �� �κ� ���� �ְų�, �Ǵ� �ٸ� ��� ���� �־�� �մϴ�.
        // ���� ���� �� �κ��� ��� ���� �ְų�, �Ǵ� ���� �� �κ��� �ٸ� ���� ���ÿ� ����Ǿ� �־�� �մϴ�.

        if (a == 0) {
            int flag = 0; // üũ��

            //�ٴ�����
            if (y == 0)
                flag = 1;
            // '���� �� �� �� �κ� ��' Ȥ�� '�ٸ� ��� ��'��� ����
            for (vector<int>& an : answer) {
                // �� ��
                if (x - 1 == an[0] && y == an[1] && 1 == an[2])
                    flag = 1;
                // �� ��
                if (x == an[0] && y == an[1] && 1 == an[2])
                    flag = 1;
                // �ٸ� ��� ��
                if (x == an[0] && y - 1 == an[1] && 0 == an[2])
                    flag = 1;
            }

            if (flag == 0)
                return 0;
        }

        else if (a == 1) {
            int flag = 0; // üũ��
            int l = 0;
            int r = 0;

            // '���� ���κ��� ��� ��' Ȥ�� '���� ���κ��� �ٸ� ���� ���ÿ� ����'�̶�� ����
            for (vector<int>& an : answer) {
                // �� ��
                if (x == an[0] && y - 1 == an[1] && 0 == an[2])
                    flag = 1;

                // �� ��
                if (x  + 1 == an[0] && y - 1 == an[1] && 0 == an[2])
                    flag = 1;

                // �� ��
                if (x - 1 == an[0] && y == an[1] && 1 == an[2])
                    l = 1;
                
                // ���� ��
                if (x + 1 == an[0] && y == an[1] && 1 == an[2])
                    r = 1;
            }
            
            if (l == 1 && r == 1) flag = 1;

            // ���� ��ȯ 
            if (flag == 0)
                return 0;
        }
    }

    return 1;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    //��ɾ�
    for (vector<int>& frame : build_frame) {
        int x = frame[0];
        int y = frame[1];
        int a = frame[2]; // ������ 0 -> ���, 1 -> ��
        int b = frame[3]; // ��ɾ� 0 -> ����, 1 -> ��ġ

        // ���� ��ɾ� �̸�
        if (b == 0) {
            answer = remove_answer(answer, x, y, a);

            //���� �� ��������?
            if (is_possible(answer) == 0) 
                answer.push_back({ x,y,a }); //�ٽ� ��ġ 
        }

        //��ġ�ϴ� ���
        if (b == 1) {
            answer.push_back({ x,y,a });
            //��ġ �� ��������?
            if (is_possible(answer) == 0)
                answer.pop_back();
        }
    }

    sort(answer.begin(), answer.end()); // �������� ����
    return answer;
}