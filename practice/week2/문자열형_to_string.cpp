#include <iostream>
#include <string>
using namespace std;

int main()
{

	string s1 = "���";
	string s2;
	//s2 = s1+ " " +10 + "��"; �� �ȵ�!
	s2 = s1 + "" + to_string(10) + "��";
	//���� �ڷ����� ���°Ŷ� ���ڿ� �������� 10 ���� ������ �׷��� ����Ʈ������ �������̶�� �˷��ִ� ��!!
	cout << s2 << endl;
}