#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople = 3; // ������� �ع�����
	//cout << "�� ���� ���� �Է��϶�: ";
	//cin >> maxPeople;
	string names[maxPeople]; //�迭�� �����ŭ�� ĭ�� ���� �ص� ����
	int ages[maxPeople];

	for (int i = 0; i < maxPeople; i++) { //for������ �����ŭ�� �� �̸��� ���̸� ���� �迭�� ����
		cout << "���" << i + 1 << "�� �̸� : ";
		cin >> names[i];
		cout << "���" << i + 1 << "�� ���� : ";
		cin >> ages[i];
	}

	int ageThreshold; //ã���� �ϴ� ���̰��� ����� ����
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> ageThreshold;

	int oldman = 0; //�� ������ if���� ���Ͽ� ���� ����� ������
	cout << ageThreshold << "�� �̻��� ���� : \n";

	for (int i = 0; i< maxPeople; i++)
		if (ages[i] >= ageThreshold) { // ���� ���̰� �̻��̶��
			cout << names[i] << "(" << ages[i] << "��)\n"; //���� �̸��� ���̸� ���
			oldman++;//������ oldman ����� �ö�
	}
	if (oldman == 0) {// if������ ���� �����ߴ� oldman�� �ö� ���� ������ ���� ������ ���
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�.";
	}

	return 0;
}