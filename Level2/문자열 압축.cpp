#include <string>
#include <vector>

using namespace std;

//�ּڰ� ��ȯ
int min(int a, int b) {
    return a < b ? a : b;
}

int solution(string s) {
    int answer = s.length();

    //���ڿ� Ž��
    //���ڿ� �����̹Ƿ� n/2��ŭ �� �ɰ�����
    for (int i = 1; i <= s.length() / 2; i++) {
        //�ӽÿ� ����
        string tmp = "", convert = "";

        int cnt = 1;
        //substr�� i�� �߶�
        tmp = s.substr(0, i);

        for (int j = i; j < s.length(); j += i) {
            if (tmp == s.substr(j, i))
                cnt++;
            else {
                //2 �̻��̸�
                if (cnt > 1)
                    convert += to_string(cnt);
                convert += tmp;
                //�ݺ��Ǵ� ���� �ٲ�� �ϹǷ�
                tmp = s.substr(j, i);
                //�ʱ�ȭ
                cnt = 1;
            }
        }
        //2 �̻��̸�
        if (cnt > 1)
            convert += to_string(cnt);
        convert += tmp;

        //���̰� ���� ������ ����
        answer = min(answer, convert.length());
    }

    //��ȯ
    return answer;
}