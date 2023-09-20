#include <iostream>
#include <time.h>
using namespace std;

int main(){
	srand(time(NULL)); //랜덤 함수 관련 설정

	int answer = rand() % 100; //정답
	int tries = 0; // 시도 횟수 저장하는 변수

	int usertry = 0; //사용자 입력값 변수


	while (usertry != answer) { //답이 아닐때마다 계속 진행
		cout << "정답을 추측하여 보십시오:" << endl;
		cin >> usertry;
		tries++; //한 회차마다 시도횟수 올라감

		if (usertry > answer)//높으면 출력
			cout << "제시한 정수가 높습니다." << endl;
		if (usertry < answer)//낮으면 출력
			cout << "제시한 정수가 낮습니다." << endl;
	
	}//답이면 탈출
	cout << "축하합니다. 시도횟수=" << tries << endl;
	return 0;
}