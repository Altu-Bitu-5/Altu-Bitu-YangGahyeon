#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int sns(string a, string b){
   int asum = 0;
   int bsum = 0;
    
    //1. A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
    if(a.size() != b.size()){
        return a.length() < b.length(); // a의 길이가 더 짧을 때
    }
//2. 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다.
for (int i = 0 ; i <a.size(); i++){
    char c = a[i];
    
    if(isdigit(c)){
        asum = asum + c - '0'; //ASCII코드에서 숫자로 변환
    }
    
}
for (int i = 0 ; i <b.size(); i++){
    char c = b[i];
    
    if(isdigit(c)){
        bsum = bsum + c - '0'; //ASCII코드에서 숫자로 변환
    }
    
}
if (asum != bsum){
    return asum < bsum;
    }
    return a < b;
//3. 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
}

int main()
{
    int n; 
    cin >> n; //n개의 시리얼 넘버 받기
    vector<string> serial(n); //시리얼 넘버 저장 공간
    for(int i =0; i < n; i++){
        cin >>serial[i];
    }
    sort(serial.begin(),serial.end(),sns);
    for(int i =0; i<serial.size();i++){
        cout << serial[i] << '\n';
    }

    return 0;
}