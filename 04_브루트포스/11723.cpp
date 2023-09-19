#include <iostream>
#include <string>

using namespace std;

int s = 0; // 비트마스크로 집합을 나타내는 전역 변수

// 원소 추가 함수
void addElement(int x) {
    s |= (1 << x);
}

// 원소 제거 함수
void removeElement(int x) {
    s &= ~(1 << x);
}

// 원소 확인 함수
void checkElement(int x) {
    if (s & (1 << x)) {
        cout << 1 << endl; // x가 있으면 1
    } else {
        cout << 0 << endl; // x가 없으면 0 출력
    }
}

// 원소 토글 함수
void toggleElement(int x) {
    s ^= (1 << x);
}

// 모든 원소를 1로 설정 (전체 집합 생성)
void setAll() {
    s = (1 << 21) - 1;
}

// 모든 원소를 0으로 설정 (공집합 생성)
void setEmpty() {
    s = 0;
}

int main() {
    ios_base::sync_with_stdio(false); //입출력 속도 향상
    cin.tie(NULL);
    
    int m;
    cin >> m;

    while (m--) {
        string cmd;
        int x;
        cin >> cmd; //add, check, remove, toggle, all, empty 확인

        if (cmd == "add") {
            cin >> x;
            addElement(x);
        } else if (cmd == "remove") {
            cin >> x;
            removeElement(x);
        } else if (cmd == "check") {
            cin >> x;
            checkElement(x);
        } else if (cmd == "toggle") {
            cin >> x;
            toggleElement(x);
        } else if (cmd == "all") {
            setAll();
        } else if (cmd == "empty") {
            setEmpty();
        }
    }

    return 0;
}