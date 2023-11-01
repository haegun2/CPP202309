#include <iostream>
#include <string>
using namespace std;

int main() {

	int count = 0; // distance 계산을 위한 변수
	string s1, s2, s3;

	cout << "문자열 3개에 대한 hamming distance를 구하는 프로그램입니다. " << endl;
	cout << "1번 문자열을 입력하세요. (공백 없이): ";
	cin >> s1;
	cout << "2번 문자열을 입력하세요. (공백 없이): ";
	cin >> s2;
	cout << "3번 문자열을 입력하세요. (공백 없이): ";
	cin >> s3;

	// TODO1: 문자열 길이를 비교하고 에러를 체크하는 코드 블록 작성

	if (s1.length() != s2.length() or s2.length() != s3.length() or s1.length() != s3.length())
		cout << "오류: 길이가 다름" << endl;

	// TODO2: 대소문자 구분없이 해밍 거리를 계산하기 위한 코드 블록 작성
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
			else if (s2[i] != s3[i]) {
				count += 1;
			}
			else if (s1[i] != s3[i]) {
				count += 1;
			}
		}
	}

	// 해밍 거리 출력 코드
	cout << "해밍 거리는 " << count << "입니다." << endl;

	return 0;
}