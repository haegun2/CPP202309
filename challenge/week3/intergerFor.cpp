#include <iostream>
using namespace std;

int main()
{
	int userInput;

	cout << "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����):";

	for (int i = 0; i < 10; i++)//i�� 10�� ���������� �ݺ��ϸ鼭 i�� 1�� ����
	{
		cin >> userInput;
		if (userInput == 0) {// 0�� �ԷµǸ� Ż��
			break;
		}

		cout << "�Է°�: " << userInput << " Ƚ�� :" << i << endl;
		//����ߴ��� ����ϴ� ��
	}

	cout << "����Ǿ����ϴ�";

	return 0;
}