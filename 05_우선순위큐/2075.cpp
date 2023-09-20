#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findNthBiggest(int n, vector<vector<int>>& matrix){ //n번째로 큰 수 찾는 함수
	priority_queue<int, vector<int>, greater<int>> pq; //최소 힙으로 가장 작은 값을 유지

	for(int i = 0; i < n; i++){	
		for(int j = 0; j < n; j++){
			pq.push(matrix[i][j]); //입력받은 행렬의 수들을 우선순위 큐에 삽입
			
			if(pq.size() > n) { //n보다 크다면 가장 작은 값을 제거해 n개를 유지시켜 준다.
			pq.pop();
			}
		}
	}

	return pq.top(); // top에 남아있는 수는 n번째로 큰 수
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; //행렬 크기 n
	cin >> n;

	vector<vector<int>> matrix(n, vector<int>(n)); //n*n 크기의 행렬 생성

	for(int i=0; i < n; i++){	//n*n이므로 n까지 행렬들을 입력 받음
		for(int j = 0; j < n; j++){
			cin >> matrix[i][j];
		}
	}
	int result = findNthBiggest(n, matrix); //n번째 큰 수를 찾는 함수 호출

	cout << result; //결과 출력

return 0;
}