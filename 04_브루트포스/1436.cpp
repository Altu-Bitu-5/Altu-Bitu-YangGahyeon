#include <iostream>
#include <string>

using namespace std;

//문자열에 666이 포함이 되어있는지 판단하는 함수
bool have666(int num){
string str_num = to_string(num); //숫자를 문자열로 변환

return str_num.find("666") != string::npos; //666이 있으면 true 반환
}

//n번째의 제목을 찾는 함수
int findNnumber(int n){
	int count = 0; //현재까지 찾은 영화의 수
	int num = 666; 

	while (count < n) {
		if(have666(num)){ //666이 포함되어 있으면
		count++; //카운트 증가
		}

		if(count != n){ //찾지 못했으면 
			num++; //다음 숫자 검사
		}
	}
	return num;
}
int main(){
	int n;
	cin >> n;

	//결과 출력
	int result = findNnumber(n);
	
	cout << result;

	return 0;
}