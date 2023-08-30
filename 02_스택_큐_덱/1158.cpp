#include <iostream>
#include <queue>

using namespace std;

//�似Ǫ�� ����
int main() {
    int N, K; //N���� ���, ���� ���� K��° ���
    cin >> N >> K; 

    queue<int> q; 

    // ť�� 1���� N������ ���� ����
    for (int i = 1; i <= N; i++)
        q.push(i);

    cout << "<";

    //��� ���� �κ�

    while (!q.empty()) { //ť�� ������� ���� ������ ����
        for (int i = 0; i < K - 1; i++) {
            // �� �տ� �ִ� ���� K-1�� ��ŭ �ڷ� ������
            q.push(q.front());  // �� ���� ť ���� ť�� �� �ڷ� ����
            q.pop();            // �� ���� ���� ť���� ����
        }

        // K��° ���� ����ϰ� ť���� ����
        cout << q.front();
        q.pop();

        // ť�� �����ִ� ��Ұ� �ִٸ� ��ǥ�� ���� ���
        if (!q.empty())
            cout << ", ";
    }

    cout << ">";

    return 0;
}