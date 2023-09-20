#include <iostream>
using namespace std;

int main()
{
	int vowel = 0;
	int consonant = 0;
	cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;

	char ch;

	while (cin >> ch) {//입력이 계속 진행됨
		switch (ch) {//그중 모음들은 vowel의 숫자를 1씩 증가
		case 'a':
			vowel++;
			break;
		case 'o':
			vowel++;
			break;
		case 'u':
			vowel++;
			break;
		case 'i':
			vowel++;
			break;
		case 'e':
			vowel++;
			break;
		default: //그 외는 자음을 1씩 증가
			consonant++;
			break;
		}

		if (ch == '^ Z') // 컨트롤 z를 하면 반복문 탈출
			break;

	}

	cout << "모음: " << vowel << endl;
	cout << "자음: " << consonant << endl;

	return 0;
}