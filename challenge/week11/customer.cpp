#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int max_people, age;
	string name;
	vector<string> names;
	vector<int> ages;

	cout << "�� ���� ���� �Է��϶�: ";
	cin >> max_people;


	for (int i = 0; i < max_people; i++) {
		cout << "���" << i + 1 << "�� �̸� : ";
		cin >> name;
		cout << "���" << i + 1 << "�� ���� : ";
		cin >> age;
		names.push_back(name);
		ages.push_back(age);
	}

	int age_threshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> age_threshold;

	int oldman = 0;
	cout << age_threshold << "�� �̻��� ���� : \n";

	for (int i = 0; i < max_people; i++)
		if (ages[i] >= age_threshold) {
			cout << names[i] << "(" << ages[i] << "��)\n";
			oldman++;
		}

	if (oldman == 0) {
		cout << age_threshold << "�̻��� ���̸� ���� ���� �����ϴ�.";
	}

	return 0;
}