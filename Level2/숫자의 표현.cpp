#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;

    int start = 1; //1�� ����
    // ���۰��� n���� Ŀ���� ������ �ݺ�
    while (start <= n) {
        int tmp = 0; //�ӽ� �պ���
        int tmp_idx = start; //�ӽ� ���۰�
        while (true) { //���õ� ���۰����� ���� ����
            //�ӽ� �� ������ n�� ���ٸ�
            if (n == tmp) {
                answer += 1; //ī��Ʈ
                break; //���� Ż��
            }
            // �ӽ����� n���� Ŀ���� 
            else if (n < tmp) break; //���� Ż��
            tmp += tmp_idx; 
            tmp_idx++;
        }
        start++;
    }
    return answer;
}