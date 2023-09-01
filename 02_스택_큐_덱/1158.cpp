#include <iostream>
#include <queue>

using namespace std;

string josephus(int N, int K){
     queue<int> q;
     string result; //결과 값 저장 

    // 큐에 1부터 N까지의 수를 삽입
    for (int i = 1; i <= N; i++)
        q.push(i);

    result += "<";

    //출력 숫자 부분

    while (!q.empty()) { //큐가 비어있지 않을 때까지 실행
        for (int i = 0; i < K - 1; i++) {
            // 맨 앞에 있는 값을 K-1번 만큼 뒤로 보내기
            q.push(q.front());  // 맨 앞의 큐 값을 큐의 맨 뒤로 보냄
            q.pop();            // 맨 앞의 값을 큐에서 제거
        }

        // K번째 값을 출력하고 큐에서 제거
        result += to_string(q.front()); 
        q.pop();

        // 큐에 남아있는 요소가 있다면 쉼표와 공백 출력
        if (!q.empty())
            result += ", ";
    }

    result += ">";

    return result;
}
//요세푸스 순열
int main() {
    int N, K; //N명의 사람, 양의 정수 K번째 사람
    cin >> N >> K; 
    
    string josephuspermutation = josephus(N,K);
    cout << josephuspermutation;
    
    return 0;
}