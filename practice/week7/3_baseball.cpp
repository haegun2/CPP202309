#include <iostream>
#include <string>
using namespace std;

int main() {
	int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
	char firstNum; // ������ ù��° �ڸ���
	char secondNum; // ������ �ι�° �ڸ���
	char thirdNum; // ������ ����° �ڸ���
	string strNum;

	while (1) {		
		randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����

		bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����

		// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
		strNum = to_string(randomNum);
		if (strNum[0] == strNum[1] or strNum[1] == strNum[2] or strNum[2] == strNum[0]) {
			same = true;
		}
		if (same == true) {
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

			bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����
			// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
			if (guessFirst == guessSecond or guessSecond == guessThird or guessFirst == guessThird) {
				same = true;
			}
			if (same == true) {
				break;
			}



			if (to_string(userNumber).length() != 3) {
				cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}

			if (same == true) {
				break;
			}
		}


		int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
		int ball = 0; // �� ������ �����ϴ� ����

		// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ��� �ۼ�
		

		//if ������ ����Ͽ� randomNum�� to_string���� ��ȯ�� ���� �� 0,1,2�� �ڸ� ���� ��ġ�ϴ��� Ȯ���ϰ�, ���� �ڸ����� ��ġ�� strike ���� 1 ����, for���� ����Ͽ� ��ġ�� ���� ������ ball ���� 1 ������Ű�� ���� �����.

		cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;
		
		if (strike == 3) {
			cout << "������ ������ϴ�. �����մϴ�.";
			break;
		}

		turn += 1;
	}

	return 0;
}
