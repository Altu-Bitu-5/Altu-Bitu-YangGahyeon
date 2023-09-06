#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

// �����佺�׳׽��� ü�� ����Ͽ� �Ҽ��� ���ϴ� �Լ�
vector<bool> primeSieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; //0�� 1�� �Ҽ� �ƴ�

    for (int p = 2; p * p <= n; p++) { // p�� n�� �����ٱ��� �ݺ�
        if (isPrime[p]) {
            // p�� ����� ��� �Ҽ��� �ƴ� ������ ǥ��
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    return isPrime; // �Ҽ� ���� �迭 ��ȯ
}

// �������� ������ �����ϰ� ����ϴ� �Լ�
void goldbachConjecture(int n, const vector<bool>& isPrime) {
    bool found = false; // �������� ������ �����ϴ� �Ҽ� ���� ã�Ҵ��� ����

    for (int i = 2; i <= n / 2; i++) {
        if (isPrime[i] && isPrime[n - i]) {
            // �������� ������ �����ϴ� �� �Ҽ� ���
            cout << n << " = " << i << " + " << n - i << '\n';
            found = true;
            break; // �� �� ã���� ���� ����
        }
    }

    if (!found)
        cout << "Goldbach's conjecture is wrong." << '\n'; // ã�� ���� ��� �޽��� ���
}

int main() {
    //����� �ӵ� ���
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // �����佺�׳׽��� ü�� ����Ͽ� �Ҽ� ��� ����
    vector<bool> isPrime = primeSieve(MAX);

    while (true) {
        int n;
        cin >> n;

        if (n == 0) //�Է� 0�� �� ���α׷� ����
            break;
            // �������� ������ �����ϰ� �Լ� ���
        goldbachConjecture(n, isPrime);
    }

    return 0;
}