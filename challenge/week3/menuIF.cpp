#include <iostream>
using namespace std;

int main() {
	int choice;

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice; //���� choice ����� ���⼭ �Է�

	if (choice == 1) //���� ���ڰ� 1�̸� 1�� ���ѳ��� ���
		cout << "���� ������ �����߽��ϴ�" << endl;
	else if(choice == 2) //���� ���ڰ� 2�̸� 2�� ���� ���� ���
		cout << "���� �ݱ⸦ �����߽��ϴ�" << endl;
	else if (choice == 3) //���� ���ڰ� 3�̸� 3�� ���� ���� ���
		cout << "���α׷��� �����մϴ�." << endl;
	else // �� �ƴϸ� �Ʒ� ���� ���
		cout << "�߸��� �����Դϴ�." << endl;

	return 0;

}