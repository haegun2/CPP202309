#include <iostream>
using namespace std;


int main() {

	int a, b, c, mini;

	cout << "3���� ������ �Է��Ͻÿ�: ";
	cin >> a >> b >> c;

	if (a < b && a < c) //a�� b�� c���� ������ °���̴� a
		mini = a;
	else if (b < a && b < c) //b�� a�� c���� ������ b�� ������
		mini = b;
	else// �� �� �ƴϸ� c�� ���� ����
		mini = c;

	cout << "���� ���� ������" << mini << endl;
	return 0;

}