#include <iostream>
#include <queue>

using namespace std;

int main(){
	int n; //�湮�� Ƚ��
	cin >>n;

	priority_queue<int> gift;

	for(int i = 0; i < n; i++){
		int a;
		cin >> a;

		if(a ==0){
			if (gift.empty()){ //ť�� ����ִٸ� -1 ���
				cout << -1 <<endl;
			}
		else{
				cout << gift.top() <<endl; //���� ū ��ġ�� ���� ���
				gift.pop();
			}
		}
	else { //0�� �ƴ϶��
		for(int j = 0; j < a; j++){ //������ ť�� ����
			int gifts;
			cin >> gifts;
			gift.push(gifts);
			}
		}
	}
	return 0;
}