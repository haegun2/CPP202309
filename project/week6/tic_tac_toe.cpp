#include<iostream>
using namespace std;

int main() {
	const int numCell = 3;
	char board[numCell][numCell]{};
	int x, y; // ����ڿ��� �Է¹��� x,y ��ǥ

	//�������� ����� ������ ���� ����
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	//�����ϴ� �ڵ�
	int k = 0;
	char currentUser = 'X'; //���� ������ ���� �����ϱ� ���� ����
	while (true) {
		//1. ��� ������ �������� ���
		switch (k % 2) { // �������� 0 1��
		case 0:
			cout << k % 2 + 1 << "�� ����(X)�� �����Դϴ� -> "; // 
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "�� ����(O)�� �����Դϴ� -> ";
			currentUser = 'O';
			break;
		}

		//2.�������� ��ǥ�Է¹ޱ�
		cout << "(x,y) ��ǥ�� �Է��ϼ���: ";
		cin >> x >> y;

		//3.�Է¹��� ��ǥ�� ��ȿ�� üũ. ������ ���� ���̰ų� �̹� ���� ���� ��
		if (x >= numCell || y >= numCell) {
			cout << x << "," << y << ":";
			cout << "x �� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
			continue;
		}
		if (board[x][y] != ' ') {
			cout << x << "," << y << ": �̹� ���� ���ֽ��ϴ�." << endl;
			continue;
		}

		//4.�Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		//5.���� ������ ���

		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl; //�� �� ����ĭ �׸���
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j]; //ĭ�� �ϳ��� �׸���
				if (j == numCell - 1) {
					break; //��������  | �ȱ׸��� Ż��
				}
				cout << "  |";
			}
			cout << endl;
		}
		cout << "---|---|---" << endl; // �� ��ĭ ����ĭ �帮��
		k++;

		//6.��� ĭ�� á���� ����
		int checked = 0; //üũ�� ���� ������ �����
		for (int i = 0; i < numCell; i++) { 
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') { // ��ĭ�� ���������� ���� ���� �߰�!!
					checked++;
				}
			}
		}
		if (checked == 0) { //�Ź� �ݺ����� �����鼭 �������� üũ�� ���̻� �߰����� ������
			cout << "��� ĭ�� �� á���ϴ�. �����մϴ�.<<endl";
			break; // ������ �ݺ��� Ż��
		}

		//7. ���� üũ
		bool isWin = false; //�¸� Ȯ���� ���� ����

		for (int i = 0; i < numCell; i++) { // ���� X�� Y ��ǥ�� i�� ������ �� �ش� ���� ��� ���� �������� ���̸� �¸� Ȯ��
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "���ο� ��� ���� �������ϴ�!: ";
				isWin = true;
			}
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "���ο� ��� ���� �������ϴ�!: ";
				isWin = true;
			}
		}// �밢���� ��� ���� ���� ������ ���� �� �������� ������ �¸�Ȯ��
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
			isWin = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
			isWin = true;
		}
		// �¸� Ȯ���� ���� ������ TRUE�� �Ǹ�, ���� ������ �¸��� ���
		if (isWin == true) {
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			cout << "�����մϴ�" << endl;
			break;
		}
	}
	return 0;
}