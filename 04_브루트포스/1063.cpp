#include<iostream>                                                                                                 
#include<string>                                                                                                   
#include<vector> //pair                                                                                            
                                                                                                                   
using namespace std;                                                                                               
typedef pair<char, char> cc; //pair<char, char> -> cc라고 정의함                                                          
                                                                                                                   
cc move(string input, char x, char y) {//이동 함수 x : 열, y : 행                                                        
    for (char how : input) {        //input에 따라서 어떻게 갈지                                                                     
        if (how == 'R') {          //오른쪽으로 이동하면 열을 증가                                                                                
            x++;                                                                                                   
        }                                                                                                          
        else if (how == 'L') {      //왼쪽으로 이동하면 열을 감소                                                                               
            x--;                                                                                                   
        }                                                                                                          
        else if (how == 'B') {     // 뒤로 이동하면 행을 감소                                                                              
            y--;                                                                                                   
        }                                                                                                          
        else {  //T인 경우                                                                                             
            y++;              // 위로 이동하면 행을 증가                                                                                    
                                                                                                                   
        }                                                                                                          
    }                                                                                                              
                                                                                                                   
    return { x, y };     // 이동 후 위치를 pair로 반환                                                                                          
                                                                                                                   
}                                                                                                                  
                                                                                                                   
bool checkRange(cc position) { //범위 체크 하는 함수                                                                       
    if (position.first < 'A' || position.first > 'H' || position.second < '1' || position.second > '8') {          
        return false;                                                                                              
    }                                                                                                              
    return true;    // 유효한 범위 내에 있으면 true를 반환                                                                                               
}                                                                                                                  
bool isSame(cc k, cc s) {      //두 위치가 같은지 확인하는 함수                                                                                                                                                      
    return (k.first == s.first && k.second == s.second);  //같다면 true 반환                                                         
}                                                                                                                  
                                                                                                                   
/*                                                                                                                 
* HINT : 문자형 변수의 연산은 비교적 자유로워요! 또 킹과 돌의 움직임이 모두 판 안에서 이뤄질 때만 다음으로 움직일 수 있는 점을 신경써주세요!                              
* 1. king 이동 (move)                                                                                                
* 2. king과 stone의 위치 동일 -> stone 이동 (move)                                                                         
* 3. king과 stone의 위치 점검 (checkRange                                                                                
*/                                                                                                                 
                                                                                                                   
int main() {                                                                                                       
                                                                                                                   
    cc k, s; // 킹(king)과 돌(stone)의 현재 위치를 나타내는 변수                                                                                         
    int n;        //명령의 개수                                                                                               
    string input;   //이동을 저장할 문자열                                                                                               
                                                                                                                   
    //입력                                                                                                           
    cin >> k.first >> k.second >> s.first >> s.second >> n;                                                        
                                                                                                                   
    //연산                                                                                                           
    while (n--) {                                                                                                  
        cin >> input;    //이동 입력                                                                                          
                                                                                                                   
        cc next_k, next_s;//이동 후 위치 저장할 변수                                                                         
                                                                                                                   
        //king 이동                                                                                                  
        next_k = move(input, k.first, k.second);                                                                   
                                                                                                                   
        //stone 이동                                                                                                 
        if (isSame(next_k,s)) {//킹과 돌 위치와 겹치면                                                                         
            next_s = move(input, s.first, s.second);     //돌 이동                                                          
        }                                                                                                          
        else {               //킹과 돌의 위치가 겹치지 않으면 이동 x                                                                                      
            next_s = s;                                                                                            
        }                                                                                                          
                                                                                                                   
        //범위 체크                                                                                                    
        if (checkRange(next_k) && checkRange(next_s)){//이동한 king과 stone가 유효 범위면 최종적으로 이동                           
            k = next_k;   //킹의 위치 업데이트                                                                                         
            s = next_s;   //돌의 위치 업데이트                                                                                         
        }                                                                                                          
                                                                                                                   
    }                                                                                                              
                                                                                                                   
    //출력                                                                                                           
    cout << k.first << k.second <<'\n'<< s.first << s.second ;                                                     
    return 0;                   
 }