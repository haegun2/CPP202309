#include <iostream>
#include <time.h>
using namespace std;

int main(){
	int i;
	int ans;
	cout << "��� ������ �ڵ����� �����մϴ�." << endl;


	while (true) {
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;

		cout << firstNum << "+" << secondNum << "=";
		cin >> ans;

		if (ans == firstNum + secondNum)
			cout << "�¾ҽ��ϴ�." << endl;
		else
			cout << "Ʋ�Ƚ��ϴ�." << endl;
	}

	return 0;
}