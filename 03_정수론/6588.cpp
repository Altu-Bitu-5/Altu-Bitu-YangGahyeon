#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

// 에라토스테네스의 체를 사용하여 소수를 구하는 함수
vector<bool> primeSieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; //0과 1은 소수 아님

    for (int p = 2; p * p <= n; p++) { // p가 n의 제곱근까지 반복
        if (isPrime[p]) {
            // p의 배수를 모두 소수가 아닌 것으로 표시
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    return isPrime; // 소수 여부 배열 반환
}

// 골드바흐의 추측을 검증하고 출력하는 함수
void goldbachConjecture(int n, const vector<bool>& isPrime) {
    bool found = false; // 골드바흐의 추측을 만족하는 소수 쌍을 찾았는지 여부

    for (int i = 2; i <= n / 2; i++) {
        if (isPrime[i] && isPrime[n - i]) {
            // 골드바흐의 추측을 만족하는 두 소수 출력
            cout << n << " = " << i << " + " << n - i << '\n';
            found = true;
            break; // 한 번 찾으면 루프 종료
        }
    }

    if (!found)
        cout << "Goldbach's conjecture is wrong." << '\n'; // 찾지 못한 경우 메시지 출력
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 에라토스테네스의 체를 사용하여 소수 목록 생성
    vector<bool> isPrime = primeSieve(MAX);

    while (true) {
        int n;
        cin >> n;

        if (n == 0) //입력 0일 때 프로그램 종료
            break;
            // 골드바흐의 추측을 검증하고 함수 출력
        goldbachConjecture(n, isPrime);
    }

    return 0;
}