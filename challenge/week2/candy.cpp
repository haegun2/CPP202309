#include <iostream>
#include <string>
using namespace std;

int main()
{
	string money;
	string cost;
	cout << "���� ������ �ִ� ��:" << endl;
	cin >> money;
	cout << "ĵ���� ����" << endl;
	cin >> cost;
	cout << "�ִ�� �� �� �ִ� ĵ��=" << money / cost << endl;
	cout << "ĵ�� ���� �� ���� ��=" << money // cost << endl;

		return 0;
}