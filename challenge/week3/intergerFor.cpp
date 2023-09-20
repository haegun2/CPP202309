#include <iostream>
using namespace std;

int main()
{
	int userInput;

	cout << "정수를 10번 입력하세요 (0을 입력하면 종료):";

	for (int i = 0; i < 10; i++)//i가 10번 써질때까지 반복하면서 i를 1씩 증가
	{
		cin >> userInput;
		if (userInput == 0) {// 0이 입력되면 탈출
			break;
		}

		cout << "입력값: " << userInput << " 횟수 :" << i << endl;
		//몇번했는지 출력하는 것
	}

	cout << "종료되었습니다";

	return 0;
}