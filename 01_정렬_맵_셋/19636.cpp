#include <iostream>
#include <tuple>
#include <cmath>

using namespace std;

tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t) { //요요 시뮬레이션 함수
    // w: 몸무게, m: 기초대사량
    int w1 = w0, m1 = i0; // 기초대사량 변화 고려 X
    int w2 = w0, m2 = i0; // 기초대사량 변화 고려 O

    while (d--) {
        // 체중 변화 계산: 체중 += 일일 에너지 섭취량 - 일일 에너지 소비량
        // 일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량
        w1 += i - (m1 + a);
        w2 += i - (m2 + a);

        // 일일 기초대사량 변화 (m2만 변화), 절댓값 이용
        if (abs(i - (m2 + a)) > t) { 
            // [주의] 음수의 나눗셈에 주의: ⌊−5 / 2⌋를 수행하면 3이 나와야 하지만
            //                              C++에서 int i = (-5) / 2를 수행할 경우 -2가 나옴
            //                              => float끼리의 나눗셈으로 수행하고 소숫점 버림
            m2 += float(i - (m2 + a)) / 2.0;
        }
    }
    return {w1, w2, m2}; // 계산한 결과값 return 
}
int main() {
    int w0, i0, i, a, d, t, final_weight, final_meta; //초기 값 설정

    cin >> w0 >> i0 >> t; // 초기 입력값 받기
    cin >> d >> i >> a; // 초기 입력값 받기

    tuple<int, int, int> tmp = diet(w0, i0, i, a, d, t); //diet 함수를 호출
    int w1 = get<0>(tmp), m1 = i0;          // 기초대사량 변화 고려 X
    int w2 = get<1>(tmp), m2 = get<2>(tmp); // 기초대사량 변화 고려 O 

    //첫 번째 결과 출력
    if (w1 <= 0) {
        // m1은 i0에서 변화하지 않고, i0는 0보다 크므로 기초대사량이 0kcal 이하가 되지 않음
        cout << "Danger Diet \n"; // 첫 번째 시뮬레이션 결과가 0 이하가 될 경우 "Danger Diet" 출력
    } else {
        cout << w1 << " " << m1 << "\n"; // 첫 번째 시뮬레이션 결과 출력
    }

    //두 번째 결과 출력
    if (w2 <= 0 || m2 <= 0) {
        cout << "Danger Diet"; // 두 번째 시뮬레이션 결과 중 하나라도 0 이하일 경우에는 "Danger Diet" 출력
    } else {
        cout << w2 << " " << m2 << " "; // 두 번째 시뮬레이션 결과 출력
        if (m2 < i0) {
            cout << "YOYO"; // 두 번째 시뮬레이션에서 기초대사량이 초기보다 작을 경우 "YOYO" 출력
        } else {
            cout << "NO"; // 두 번째 시뮬레이션에서 기초대사량이 초기보다 크거나 같을 경우 "NO" 출력
        }
    }
    return 0;
}