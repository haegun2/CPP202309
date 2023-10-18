#include <iostream>
#include <string>
using namespace std;

//전역변수 및 함수원형 생성
string s1, s2;
string toLowerStr(string str);
string toUpperStr(string str);
int calcHammingDist(string str1, string str2);

int main() {

	//사용자에게 두개의 문자열을 입력받음
	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	//해밍거리를 계산하는 함수를 호출 후 결과값 받아 출력
	int resultcount = calcHammingDist(s1, s2);
	cout << "해밍 거리는 " << resultcount << endl;
}

string toLowerStr(string str) {
	//들어오는 문자열을 활용할 새 문자열변수를 생성하여
	string newstr = str;
	//그것을 반복문으로 글자 하나 하나를 참조자기반 매개변수로 소문자화
	for (auto &c : newstr) {
		c = tolower(c);
	}
	//소문자로 변경된 새 문자열 변수를 반환
	return newstr;
}

string toUpperStr(string str) {
	//들어오는 문자열을 활용할 새 문자열변수를 생성하여
	string newstr = str;
	//그것을 반복문으로 글자 하나 하나를 참조자기반 매개변수로 대문자화
	for (auto& c : str) {
		c = toupper(c);
	}
	//대문자로 변경된 새 문자열 변수를 반환
	return newstr;
}

int calcHammingDist(string str1, string str2) {
	//s1과 s2를 모두 소문자로 변경한 값으로 재지정
	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);
	//해밍거리 산술을 위한 int변수 를 생성
	int count = 0;
	// s1과 s2가 길이가 다르면 오류 출력
	if (s1.length() != s2.length())
		cout << "오류 : 길이가 다름" << endl;
	//아니면 반복문에 대하여 문자열 s1과 s2의 i항 항목을 각 비교하여 다르면 count변수를 1씩 증가
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
	}
	//count 값을 반환
	return count;
}