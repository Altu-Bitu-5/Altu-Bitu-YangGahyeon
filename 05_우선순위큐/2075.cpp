#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findNthBiggest(int n, vector<vector<int>>& matrix){ //n��°�� ū �� ã�� �Լ�
	priority_queue<int, vector<int>, greater<int>> pq; //�ּ� ������ ���� ���� ���� ����

	for(int i = 0; i < n; i++){	
		for(int j = 0; j < n; j++){
			pq.push(matrix[i][j]); //�Է¹��� ����� ������ �켱���� ť�� ����
			
			if(pq.size() > n) { //n���� ũ�ٸ� ���� ���� ���� ������ n���� �������� �ش�.
			pq.pop();
			}
		}
	}

	return pq.top(); // top�� �����ִ� ���� n��°�� ū ��
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; //��� ũ�� n
	cin >> n;

	vector<vector<int>> matrix(n, vector<int>(n)); //n*n ũ���� ��� ����

	for(int i=0; i < n; i++){	//n*n�̹Ƿ� n���� ��ĵ��� �Է� ����
		for(int j = 0; j < n; j++){
			cin >> matrix[i][j];
		}
	}
	int result = findNthBiggest(n, matrix); //n��° ū ���� ã�� �Լ� ȣ��

	cout << result; //��� ���

return 0;
}