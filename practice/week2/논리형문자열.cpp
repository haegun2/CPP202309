#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "good";
	string s2 = "bad";
	bool b = (s1 == s2);
	cout << b << endl;
	//s1�̶� s2�� ������ b�� ����ؼ� Ʈ�縦 �����ڴٴ� �ǵ� s1�̶� s2�� �ٸ�!

	s2 = "good";
	b = (s1 == s2);
	cout << b << endl;
	//s2�� �����ִ� ���� Ʈ�簡 ��
}