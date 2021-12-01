#include <iostream>

using namespace std;

//�ִ�����
int gcd(int w, int h) {
    if (w % h == 0)
        return h;
    else
        return gcd(h, w % h);
}

long long solution(int w, int h) {
    long long answer = 1;

    //�밢������ �������� w�� h�� �ִ����� ��ŭ �ݺ��ϸ� ������
    //���� ���ΰ� w,h�� �ִ�������ŭ �ݺ��ϹǷ� 
    //���� ���δ� w,h�� �ִ������� ���� ��
    //�߶����� �簢���� ������ (���� + ���� - 1) * �ִ�����

    //(w*h)-(w+h-�ִ�����)

    answer = (long long)w * (long long)h - (w + h);
    answer += gcd(w, h);

    return answer;
}