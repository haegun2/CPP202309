#include <iostream>
#include <string>
using namespace std;

int main() {
	//���ڿ��� �����ϰ�, �عְŸ��� ������ ������ ������ ����
	string s1, s2;
	int count = 0;

	//����ڿ��� �ΰ��� ���ڿ��� �Է¹���
	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	//�� ���ڿ��� ���̸� ���Ͽ�, ���̰� �ٸ��� �񱳰� �Ұ����� �ȳ��ϴ� ������ ���
	if (s1.length() != s2.length()) 
		cout << "���� : ���̰� �ٸ�" << endl;
	//���ڿ� ���̰� �ٸ��� �ƴ϶��, �ݺ����� ���Ͽ� i ��°�� �������� �� ���ڿ��� ���Ͽ� �ٸ��� �عְŸ� ������ 1�� ����
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i]) 
				count += 1;
		}
		cout << "�ع� �Ÿ��� " << count << endl;
	}
}