#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    vector<long long> v; //�ӵ��� ���� ����
    v.push_back(0);
    
    //�Է�
    cin >> n;
    for(int i=1; i<=n; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    //����� ���� �ӵ��� ���ϸ鼭 �ּ� �ӵ� ���
    for(int i=n-1; i>=1; i--){
        if(v[i] < v[i+1]){//���� ���� �ӵ��� ���� �ӵ����� ������
            long long times = (v[i+1]-1) / v[i] + 1; //���� �ӵ��� �� ��� �÷����ϴ� �� ���
            v[i] *= times; //���� �ӵ� ����
        }
    }

    cout << v[1];

    return 0;
}