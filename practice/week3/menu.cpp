#include <iostream>
using namespace std;

int main() {
	int choice;

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice; //���� choice ����� ���⼭ �Է�

	switch (choice) {
	case 1 ://���� ���ڰ� 1�̸� 1�� ���ѳ��� ���
		cout << "���� ������ �����߽��ϴ�" << endl;
		break; //������ ���⼭ Ż�� �ƴϸ� ������
	case 2 : //���� ���ڰ� 2�̸� 2�� ���� ���� ���
		cout << "���� �ݱ⸦ �����߽��ϴ�" << endl;
		break;//������ ���⼭ Ż�� �ƴϸ� ������
	case 3 : //���� ���ڰ� 3�̸� 3�� ���� ���� ���
		cout << "���α׷��� �����մϴ�." << endl;
		break;
	default:// �� �ƴϸ� �Ʒ� ���� ���
		cout << "�߸��� �����Դϴ�." << endl;
		break;

	}
	return 0;
}