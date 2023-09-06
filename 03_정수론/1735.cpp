#include <iostream>

using namespace std;

// 최대 공약수를 계산하는 함수
int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main() {
    // 입력 받기
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // 두 분수의 합 구하기
    int numerator = a * d + b * c; //분자
    int denominator = b * d; //분모

    // 최대 공약수 계산
    int gcd = GCD(numerator, denominator);

    // 기약 분수로 만들기
    numerator /= gcd; //분자 최대공약수로 나누기
    denominator /= gcd; //분모 최대공약수로 나누기

    // 출력
    cout << numerator << ' ' << denominator << endl;

    return 0;
}