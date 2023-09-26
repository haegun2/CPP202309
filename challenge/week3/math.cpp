#include <iostream>
#include <time.h>
using namespace std;

int main(){
	int i;
	int ans; //변수로 i 와 ans 를 지정
	cout << "산수 문제를 자동으로 출제합니다." << endl;


	while (true) {
		int firstNum = rand() % 100; //랜덤으로ㅓ 첫 숫자를 저장
		int secondNum = rand() % 100; //랜덤으로 둘째 숫자 저장

		cout << firstNum << "+" << secondNum << "="; //두 숫자의 합을 물어봄
		cin >> ans; //정답을 사용자로부터 받아 ans에 저장

		if (ans == firstNum + secondNum)
			cout << "맞았습니다." << endl; //정답시 출력
		else
			cout << "틀렸습니다." << endl; //오답시 출력
	}

	return 0;
}
