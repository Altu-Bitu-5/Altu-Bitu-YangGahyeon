#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addString(string Anum, string Bnum){     //���ϴ� �Լ� ����
    int i = Anum.size() - 1; // num1�� ������ �ڸ� �ε���
    int j = Bnum.size() - 1; // num2�� ������ �ڸ� �ε���
    int carry = 0; // �ڸ� �ø� ó�� ����, carry �̿�
    string result = ""; // ����� ������ ���ڿ� ����

    // ������ ������ �� �ִ� ���� �ݺ�
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        // �� ������ �ڸ����� ����
        if (i >= 0) {
            sum += Anum[i] - '0'; // ���ڸ� ������ ��ȯ�Ͽ� ����
            i--;
        }
        if (j >= 0) {
            sum += Bnum[j] - '0'; // ���ڸ� ������ ��ȯ�Ͽ� ����
            j--;
        }

        carry = sum / 10; // �ø� ó��
        result =  result + to_string(sum % 10); // ����� ���� �ڸ����� �߰�
    }

    reverse(result.begin(), result.end()); // ����� ������ ��, ���� �ڸ��������� �������Ƿ�

    return result;
}

int main() {
    string A, B; //ū ���� �ޱ� ���� string �̿�
    cin >> A >> B; 

    string result = addString(A,B);
    cout << result ;

    return 0;
}