#include <iostream>
using namespace std;

int main()
{
	int vowel = 0;
	int consonant = 0;
	cout << "�����ڸ� �Է��ϰ� ctrl+z�� ġ����" << endl;

	char ch;

	while (cin >> ch) {//�Է��� ��� �����
		switch (ch) {//���� �������� vowel�� ���ڸ� 1�� ����
		case 'a':
			vowel++;
			break;
		case 'o':
			vowel++;
			break;
		case 'u':
			vowel++;
			break;
		case 'i':
			vowel++;
			break;
		case 'e':
			vowel++;
			break;
		default: //�� �ܴ� ������ 1�� ����
			consonant++;
			break;
		}

		if (ch == '^ Z') // ��Ʈ�� z�� �ϸ� �ݺ��� Ż��
			break;

	}

	cout << "����: " << vowel << endl;
	cout << "����: " << consonant << endl;

	return 0;
}