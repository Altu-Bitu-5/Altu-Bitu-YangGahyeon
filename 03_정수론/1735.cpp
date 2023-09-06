#include <iostream>

using namespace std;

// �ִ� ������� ����ϴ� �Լ�
int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main() {
    // �Է� �ޱ�
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // �� �м��� �� ���ϱ�
    int numerator = a * d + b * c; //����
    int denominator = b * d; //�и�

    // �ִ� ����� ���
    int gcd = GCD(numerator, denominator);

    // ��� �м��� �����
    numerator /= gcd; //���� �ִ������� ������
    denominator /= gcd; //�и� �ִ������� ������

    // ���
    cout << numerator << ' ' << denominator << endl;

    return 0;
}