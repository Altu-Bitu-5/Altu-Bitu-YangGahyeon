#include <iostream>
#include <vector>

using namespace std;
const int NUM_CHARS = 26; //A부터 Z까지 알파벳 개수 상수로 정의

void countFreq(string word, vector<int> &freq){	//문자열의 빈도수를 카운트하는 함수 
	for(int i = 0; i <word.length(); i++){
		freq[word[i] - 'A']++; //아스키 코드 값으로 빈도수 증가
	}
}

int countDiff(string word, vector<int> original_freq) {// 두 문자열 간 빈도수 차이를 계산하는 함수
    vector<int> freq(NUM_CHARS, 0); //빈도수를 저장할 배열 초기화
    int different = 0; // 원본 단어와의 차이를 나타내는 변수

    countFreq(word, freq); // 각 알파벳의 개수 세는 함수 호출
    
    // 원본 단어와 다른 알파벳 개수 구하기
    for (int i = 0; i < NUM_CHARS; i++) {
        different += abs(original_freq[i] - freq[i]); //원본 빈도수랑 현재 단어의 빈도수 차이를 누적시킴
    }
    return different; //얼마나 차이나는지 반환
}


int main(){

	int N, result=0; //단어의 개수와 결과 변수
    string original; //원본 단어 저장할 문자열
    // 입력
    cin >> N;
    cin >> original;
    vector<int> original_freq(NUM_CHARS, 0); //원본 단어의 빈도수를 저장할 배열

    // 빈도수 계산
    countFreq(original, original_freq);

    for (int i = 1; i < N; i++) { //나머지 단어에 대한 반복문
        string word;
        cin >> word;

        int diff = countDiff(word, original_freq); //원본과의 빈도수 차이 계산
        // 비슷한 단어 세기 -> 차이가 0, 1, 2이면서 단어의 길이가 같을 때
        if (diff == 0 || diff == 1 || diff == 2 && original.length() == word.length()) {
            result++; //정답 변수 증가
        }
    }
    // 출력
    cout << result;
    return 0;
}