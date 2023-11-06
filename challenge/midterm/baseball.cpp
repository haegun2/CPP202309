#include <iostream>
#include <string>
using namespace std;

bool checkNumber(string a);

int main() {
	int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
	char firstNum; // ������ ù��° �ڸ���
	char secondNum; // ������ �ι�° �ڸ���
	char thirdNum; // ������ ����° �ڸ���
	string strNum;

	while (1) {
		randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����

		bool same1 = false; // ��� ���� �ٸ� ��� true�� ���� ����

		// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
		strNum = to_string(randomNum);
		same1 = checkNumber(strNum);

		if (same1 == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

		int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
		string strUsernum;

		// ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
		while (1) {
			cout << "���ڸ� ���� �Է����ּ���: ";
			cin >> userNumber;

			strUsernum = to_string(userNumber);
			char guessFirst = strUsernum[0];// ������ ������ ù��° �ڸ���
			char guessSecond = strUsernum[1]; // ������ ������ �ι�° �ڸ���
			char guessThird = strUsernum[2]; // ������ ������ ����° �ڸ���
			
			bool same2 = false; // ��� ���� �ٸ� ��� true�� ���� ����
			// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
			if (guessFirst != guessSecond && guessSecond != guessThird && guessThird != guessFirst) {
				same2 = true;
			}
			if (same2 == false) {
				cout << "�Է��� ���ڿ� �ߺ��� ���ڰ� �ֽ��ϴ�. �ٽ� �Է��ϼ���\n";
					continue;
			}
			if (to_string(userNumber).length() != 3) {
				cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}
			if (same2 == true) {
				break;
			}
		}

		int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
		int ball = 0; // �� ������ �����ϴ� ����

		// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ��� �ۼ�
		for (int i = 0; i < 3; i++) {
			if (strNum[i] == strUsernum[i]) {
				strike++;
			}
		}
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (strNum[j] == strUsernum[k]) {
					ball++;
				}
			}
		}
		ball -= strike;

		cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;

		if (strike == 3) {
			cout << "������ ������ϴ�. �����մϴ�.";
			break;
		}
		turn += 1;
	}
	return 0;
}

bool checkNumber(string str) {
	if (str[0] != str[1] && str[1] != str[2] && str[2] != str[0]) {
		return true;
	}
	return false;
}