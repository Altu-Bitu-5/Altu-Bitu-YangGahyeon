#include <iostream>
#include <queue>

using namespace std;

int main(){
	int n; //방문한 횟수
	cin >>n;

	priority_queue<int> gift;

	for(int i = 0; i < n; i++){
		int a;
		cin >> a;

		if(a ==0){
			if (gift.empty()){ //큐가 비어있다면 -1 출력
				cout << -1 <<endl;
			}
		else{
				cout << gift.top() <<endl; //가장 큰 가치의 선물 출력
				gift.pop();
			}
		}
	else { //0이 아니라면
		for(int j = 0; j < a; j++){ //선물을 큐에 삽입
			int gifts;
			cin >> gifts;
			gift.push(gifts);
			}
		}
	}
	return 0;
}