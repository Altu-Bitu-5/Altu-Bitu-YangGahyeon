#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    vector<long long> v; //속도를 위한 벡터
    v.push_back(0);
    
    //입력
    cin >> n;
    for(int i=1; i<=n; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    //현재와 다음 속도를 비교하면서 최소 속도 계산
    for(int i=n-1; i>=1; i--){
        if(v[i] < v[i+1]){//만약 현재 속도가 다음 속도보다 느리면
            long long times = (v[i+1]-1) / v[i] + 1; //현재 속도에 몇 배로 늘려야하는 지 계산
            v[i] *= times; //현재 속도 저장
        }
    }

    cout << v[1];

    return 0;
}