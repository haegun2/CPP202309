#include <iostream>
using namespace std;


int main() {
	int number;

	cout << "¼ýÀÚ¸¦ ÀÔ·ÂÇÏ½Ã¿À :";
	cin >> number; //사용자로부터 숫자를 입력받은 뒤 변수 number로 지정

	if (number == 0)
		cout << "zero" <<endl; //만약 0이 들어오면 zero 출력
	else if (number == 1)
		cout << "one" << endl; // 아니면 만약 1이 들어오면  one 출력
	else
		cout << "many" << endl; // 아니면 다른게 들어오면 many 출력

	return 0;
}
