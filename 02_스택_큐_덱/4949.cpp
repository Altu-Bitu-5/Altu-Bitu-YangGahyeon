#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    while (true) {
        string input;
        getline(cin, input); //�� ���� ���ڿ��� �Է¹޾� input ������ ����

        // �Է��� "."�� ��� ����
        if (input == ".")
            break;

        stack<char> s; //��ȣ ������ ����
        bool isBalanced = true; 

        for (int i = 0; i < input.length(); i++) {
            char ch = input[i];
            if (ch == '(' || ch == '[') {
                s.push(ch);  // ���� ��ȣ�� ��� ���ÿ� push
            }
            else if (ch == ')' || ch == ']') { 
                // �ݴ� ��ȣ�� ��� ������ ����ְų� ¦�� ���� �ʴ� ���
                if (s.empty() || (ch == ')' && s.top() != '(') || (ch == ']' && s.top() != '[')) {
                    isBalanced = false; //false ��ȯ
                    break;
                }
                s.pop();  // ¦�� �´� ��� ���ÿ��� pop
            }
        }

        // ��� �Է��� ó���� �Ŀ��� ���ÿ� ���� ��ȣ�� �ִ� ���
        if (!s.empty())
            isBalanced = false;

        // ��� ���
        if (isBalanced) //true ���� ���
            cout << "yes" << endl;
        else //false ���� ���
            cout << "no" << endl;
    }

    return 0;
}
