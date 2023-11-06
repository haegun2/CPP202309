#include <iostream>
using namespace std;

// ������ �����ϴ� �� �ʿ��� ���� ����
const int numCell = 15; // �������� ���� ���� ����
int k = 0; // ���� �������� üũ�ϱ� ���� ����
char currentUser = 'X'; // ���� ������ ���� �����ϱ� ���� ����
char board[numCell][numCell]{}; // �������� ��Ÿ���� 2���� �迭
int x, y = 0; // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����
bool isWin = false; // �¸� ����

//�Լ����� ����
int isValid(int a, int b);
bool checkWin();

int main() {
	// ������ �ʱ�ȭ
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}
	// ������ ���� �ݺ�
	while (true) {
		// 1. ���� �������� ���
		// TODO 1.1: 3�ο� �������� ����
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:
			currentUser = 'O';
			break;
		case 2:
			currentUser = 'H';
			break;
		}
		cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �����Դϴ�. -> ";

		// 2. ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		int x, y;
		cin >> x >> y;

		// 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		// TODO FUNC 1: isValid �Լ� ���� �� ȣ��
		int f = isValid(x, y);
		if (f == 1) {
			continue;
		}

		// 4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		// 5. ���� ���� �� ���
		// TODO 1.2: numCell ���ڿ� ���� ������ ���
		for (int i = 0; i < numCell; i++) {
			for (int k = 0; k < numCell - 1; k++) {
				cout << "---|";
			}
			cout << "---" << endl;
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		for (int l = 0; l < numCell - 1; l++) {
			cout << "---|";
		}
		cout << "---" << endl;

		// TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
		isWin = checkWin();

		// �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.
		if (isWin == true) {
			cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			break;
		}

		// 7. ��� ĭ �� á���� üũ�ϱ�
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
			break;
		}

		k++;
	}

	return 0;
}

int isValid(int a, int b) {

	int errorResult = 0;

	if (a >= numCell || b >= numCell) {// ��ǥ ������ �����
		cout << a << "," << b << ": x�� y���� �ϳ��� ĭ�� ����ϴ�. " << endl;
		errorResult = 1;
	}
	if (board[a][b] != ' ') {// ��ǥ������ �Է°��� �ߺ��ɶ�
		cout << a << "," << b << ": �̹� ���� ���ֽ��ϴ�. " << endl;
		errorResult = 1;
	}
	return errorResult;
}

bool checkWin() {

	bool miniWin = false;

	// 6.1. ����/���� �� üũ�ϱ�
	for (int i = 0; i < numCell; i++) {
		if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
			cout << "���ο� ��� ���� �������ϴ�!!";
			miniWin = true;
			break;
		}
		if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
			cout << "���ο� ��� ���� �������ϴ�!!";
			miniWin = true;
			break;
		}
	}
	// 6.2. �밢���� üũ�ϱ�
	// TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ��
	//HINT: for ��

	int ansCheck = 0;
	for (int i = 0; i < numCell; i++) {
		if (board[i][i] == currentUser) {
			ansCheck += 1;
		}
	}
	if (ansCheck == numCell) {
		cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
		miniWin = true;
	}
	ansCheck = 0;
	for (int i = 0; i < numCell; i++) {
		if (board[i][numCell - 1 - i] == currentUser) {
			ansCheck += 1;
		}
	}
	if (ansCheck == numCell) {
		cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
		miniWin = true;
	}
	return miniWin;
}