#include <iostream>
using namespace std;

int main() {
	//���� ���� �������� ����� �����ϰ�, �װ��� ������� �ϴ� 2���� �迭 userPreferences�� ����
	const int NUM_USERS = 3;
	const int NUM_ITEMS = 3;
	int userPreferences[NUM_USERS][NUM_ITEMS];

	//����ڿ� �׸� ���� ��ȣ���� �Է� �޾� 2���� �迭 �ʱ�ȭ
	for (int i = 0; i < NUM_USERS; ++i) {
		//����� ���� ���� ���ʴ�� ����� �� ���� �迭�� ����
		cout << "����� " << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ����):";
		for (int j = 0; j < NUM_USERS; ++j) {
			cin >> userPreferences[i][j];
		}
	}

	// �� ����ڿ� ���� ��õ �׸� ã��
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}

		// ����ڿ��� ��õ�ϴ� �׸� ��õ
		cout << "�����" << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}

	return 0;
}