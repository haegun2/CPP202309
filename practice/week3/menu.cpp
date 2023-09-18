#include <iostream>
using namespace std;

int main() {
	int choice;

	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice; //변수 choice 만들고 여기서 입력

	switch (choice) {
	case 1 ://들어온 숫자가 1이면 1에 관한내용 출력
		cout << "파일 저장을 선택했습니다" << endl;
		break; //맞으면 여기서 탈출 아니면 밑으로
	case 2 : //들어온 숫자가 2이면 2에 관한 내용 출력
		cout << "파일 닫기를 선택했습니다" << endl;
		break;//맞으면 여기서 탈출 아니면 밑으로
	case 3 : //들어온 숫자가 3이면 3에 관한 내용 출력
		cout << "프로그램을 종료합니다." << endl;
		break;
	default:// 다 아니면 아래 문구 출력
		cout << "잘못된 선택입니다." << endl;
		break;

	}
	return 0;
}