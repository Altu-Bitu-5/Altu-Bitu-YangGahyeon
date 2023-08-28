#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int sns(string a, string b){
   int asum = 0;
   int bsum = 0;
    
    //1. A�� B�� ���̰� �ٸ���, ª�� ���� ���� �´�.
    if(a.size() != b.size()){
        return a.length() < b.length(); // a�� ���̰� �� ª�� ��
    }
//2. ���̰� ���ٸ�, A�� ��� �ڸ����� �հ� B�� ��� �ڸ����� ���� ���ؼ� ���� ���� ������ ���� �����´�.
for (int i = 0 ; i <a.size(); i++){
    char c = a[i];
    
    if(isdigit(c)){
        asum = asum + c - '0'; //ASCII�ڵ忡�� ���ڷ� ��ȯ
    }
    
}
for (int i = 0 ; i <b.size(); i++){
    char c = b[i];
    
    if(isdigit(c)){
        bsum = bsum + c - '0'; //ASCII�ڵ忡�� ���ڷ� ��ȯ
    }
    
}
if (asum != bsum){
    return asum < bsum;
    }
    return a < b;
//3. 1,2�� �� �������ε� ���� �� ������, ���������� ���Ѵ�. ���ڰ� ���ĺ����� ���������� �۴�.
}

int main()
{
    int n; 
    cin >> n; //n���� �ø��� �ѹ� �ޱ�
    vector<string> serial(n); //�ø��� �ѹ� ���� ����
    for(int i =0; i < n; i++){
        cin >>serial[i];
    }
    sort(serial.begin(),serial.end(),sns);
    for(int i =0; i<serial.size();i++){
        cout << serial[i] << '\n';
    }

    return 0;
}