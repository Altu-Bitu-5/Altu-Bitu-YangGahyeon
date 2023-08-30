#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addString(string Anum, string Bnum){     //더하는 함수 구현
    int i = Anum.size() - 1; // num1의 마지막 자리 인덱스
    int j = Bnum.size() - 1; // num2의 마지막 자리 인덱스
    int carry = 0; // 자리 올림 처리 변수, carry 이용
    string result = ""; // 결과를 저장할 문자열 저장

    // 덧셈을 진행할 수 있는 동안 반복
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        // 각 숫자의 자릿수를 더함
        if (i >= 0) {
            sum += Anum[i] - '0'; // 문자를 정수로 변환하여 더함
            i--;
        }
        if (j >= 0) {
            sum += Bnum[j] - '0'; // 문자를 정수로 변환하여 더함
            j--;
        }

        carry = sum / 10; // 올림 처리
        result =  result + to_string(sum % 10); // 결과에 현재 자릿수를 추가
    }

    reverse(result.begin(), result.end()); // 결과를 뒤집어 줌, 낮은 자리에서부터 더했으므로

    return result;
}

int main() {
    string A, B; //큰 수를 받기 위해 string 이용
    cin >> A >> B; 

    string result = addString(A,B);
    cout << result ;

    return 0;
}