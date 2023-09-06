#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& input){
    stack<char> s; //괄호 저장할 스택

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (ch == '(' || ch == '[') {
            s.push(ch);  // 여는 괄호일 경우 스택에 push
         }
          else if (ch == ')' || ch == ']') { 
         // 닫는 괄호일 경우 스택이 비어있거나 짝이 맞지 않는 경우
             if (s.empty() || (ch == ')' && s.top() != '(') || (ch == ']' && s.top() != '[')) {
                 return false; //false 반환
                }
                s.pop();  // 짝이 맞는 경우 스택에서 pop
            }
        }
    return s.empty();
}

void Result(const string& input){
    // 결과 출력
        if (isBalanced(input)){ //true 값일 경우
            cout << "yes" << endl;
        }
        else //false 값일 경우
            cout << "no" << endl;
}
int main() {
    while (true) {
        string input;
        getline(cin, input); //한 줄의 문자열을 입력받아 input 변수에 저장

        // 입력이 "."일 경우 종료
        if (input == ".")
            break;

        Result(input);

        
    }

    return 0;
}
