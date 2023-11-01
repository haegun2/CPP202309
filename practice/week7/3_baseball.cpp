#include <iostream>
#include <string>
using namespace std;

int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	char firstNum; // 정답의 첫번째 자리수
	char secondNum; // 정답의 두번째 자리수
	char thirdNum; // 정답의 세번째 자리수
	string strNum;

	while (1) {		
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		strNum = to_string(randomNum);
		if (strNum[0] == strNum[1] or strNum[1] == strNum[2] or strNum[2] == strNum[0]) {
			same = true;
		}
		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		string strUsernum;

		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			strUsernum = to_string(userNumber);
			char guessFirst = strUsernum[0];// 추측한 숫자의 첫번째 자리수
			char guessSecond = strUsernum[1]; // 추측한 숫자의 두번째 자리수
			char guessThird = strUsernum[2]; // 추측한 숫자의 세번째 자리수

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
			if (guessFirst == guessSecond or guessSecond == guessThird or guessFirst == guessThird) {
				same = true;
			}
			if (same == true) {
				break;
			}



			if (to_string(userNumber).length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}

			if (same == true) {
				break;
			}
		}


		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
		

		//if 문을을 사용하여 randomNum을 to_string으로 변환한 값의 각 0,1,2의 자리 값이 일치하는지 확인하고, 같은 자리에서 겹치면 strike 값을 1 증가, for문을 사용하여 겹치는 값이 있으면 ball 값을 1 증가시키는 식을 만든다.

		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;
		
		if (strike == 3) {
			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		turn += 1;
	}

	return 0;
}
