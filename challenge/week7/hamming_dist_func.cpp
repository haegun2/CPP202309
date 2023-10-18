#include <iostream>
#include <string>
using namespace std;

//�������� �� �Լ����� ����
string s1, s2;
string toLowerStr(string str);
string toUpperStr(string str);
int calcHammingDist(string str1, string str2);

int main() {

	//����ڿ��� �ΰ��� ���ڿ��� �Է¹���
	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	//�عְŸ��� ����ϴ� �Լ��� ȣ�� �� ����� �޾� ���
	int resultcount = calcHammingDist(s1, s2);
	cout << "�ع� �Ÿ��� " << resultcount << endl;
}

string toLowerStr(string str) {
	//������ ���ڿ��� Ȱ���� �� ���ڿ������� �����Ͽ�
	string newstr = str;
	//�װ��� �ݺ������� ���� �ϳ� �ϳ��� �����ڱ�� �Ű������� �ҹ���ȭ
	for (auto &c : newstr) {
		c = tolower(c);
	}
	//�ҹ��ڷ� ����� �� ���ڿ� ������ ��ȯ
	return newstr;
}

string toUpperStr(string str) {
	//������ ���ڿ��� Ȱ���� �� ���ڿ������� �����Ͽ�
	string newstr = str;
	//�װ��� �ݺ������� ���� �ϳ� �ϳ��� �����ڱ�� �Ű������� �빮��ȭ
	for (auto& c : str) {
		c = toupper(c);
	}
	//�빮�ڷ� ����� �� ���ڿ� ������ ��ȯ
	return newstr;
}

int calcHammingDist(string str1, string str2) {
	//s1�� s2�� ��� �ҹ��ڷ� ������ ������ ������
	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);
	//�عְŸ� ����� ���� int���� �� ����
	int count = 0;
	// s1�� s2�� ���̰� �ٸ��� ���� ���
	if (s1.length() != s2.length())
		cout << "���� : ���̰� �ٸ�" << endl;
	//�ƴϸ� �ݺ����� ���Ͽ� ���ڿ� s1�� s2�� i�� �׸��� �� ���Ͽ� �ٸ��� count������ 1�� ����
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
	}
	//count ���� ��ȯ
	return count;
}