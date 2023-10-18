#include <iostream>
#include <string>
using namespace std;

int main() {
	//문자열을 생성하고, 해밍거리가 몇인지 측정할 변수를 선언
	string s1, s2;
	int count = 0;

	//사용자에게 두개의 문자열을 입력받음
	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	//두 문자열의 길이를 비교하여, 길이가 다르면 비교가 불가함을 안내하는 문구를 출력
	if (s1.length() != s2.length()) 
		cout << "오류 : 길이가 다름" << endl;
	//문자열 길이가 다른게 아니라면, 반복문을 통하여 i 번째의 순서에서 두 문자열을 비교하여 다르면 해밍거리 변수를 1씩 증가
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i]) 
				count += 1;
		}
		cout << "해밍 거리는 " << count << endl;
	}
}