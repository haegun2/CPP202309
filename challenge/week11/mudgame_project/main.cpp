#include "user.h"

using namespace std;

//�� ũ�⸦ ����� ����
const int mapX = 5;
const int mapY = 5;


// ����� ���� �Լ� : �Լ������� ����
bool CheckXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(int map[][mapX], int user_x, int user_y);
bool CheckGoal(int map[][mapX], int user_x, int user_y);
void CheckState(int map[][mapX], int user_x, int user_y, User &check);
bool CheckUser(User check);

// ����  �Լ�
int main() {
	User my_user{};
	
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
							{1, 0, 0, 2, 0},
							{0, 0, 0, 0, 0},
							{0, 2, 3, 0, 0},
							{3, 0, 0, 0, 2} };


	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ


	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ����
		string user_input = "";

		cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			user_y -= 1;
			bool inMap = CheckXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y += 1;
			}
			else {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				DisplayMap(map, user_x, user_y);
				my_user.DecreaseHP(1);
				CheckState(map, user_x, user_y, my_user);
				if (CheckUser(my_user) == false) {
					cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
					cout << "������ �����մϴ�." << endl;
					break;
				}
				cout << "���� HP : " << my_user.GetHP() << "  ";
			}
		}
		else if (user_input == "��") {
			// TODO: �Ʒ��� �� ĭ ��������
			user_y += 1;
			bool inMap = CheckXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y -= 1;
			}
			else {
				cout << "���� �� ĭ �������ϴ�." << endl;
				DisplayMap(map, user_x, user_y);
				my_user.DecreaseHP(1);
				CheckState(map, user_x, user_y, my_user);
				if (CheckUser(my_user) == false) {
					cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
					cout << "������ �����մϴ�." << endl;
					break;
				}
				cout << "���� HP : " << my_user.GetHP() << "  ";
			}
		}
		else if (user_input == "��") {
			// TODO: �������� �̵��ϱ�
			user_x -= 1;
			bool inMap = CheckXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x += 1;
			}
			else {
				cout << "�������� �̵��մϴ�." << endl;
				DisplayMap(map, user_x, user_y);
				my_user.DecreaseHP(1);
				CheckState(map, user_x, user_y, my_user);
				if (CheckUser(my_user) == false) {
					cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
					cout << "������ �����մϴ�." << endl;
					break;
				}
				cout << "���� HP : " << my_user.GetHP() << "  ";
			}
		}
		else if (user_input == "��") {
			// TODO: ���������� �̵��ϱ�
			user_x += 1;
			bool inMap = CheckXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x -= 1;
			}
			else {
				cout << "���������� �̵��մϴ�." << endl;
				DisplayMap(map, user_x, user_y);
				my_user.DecreaseHP(1);
				CheckState(map, user_x, user_y, my_user);
				if (CheckUser(my_user) == false) {
					cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
					cout << "������ �����մϴ�." << endl;
					break;
				}
				cout << "���� HP : " << my_user.GetHP() << "  ";
			}
		}
		else if (user_input == "����") {
			// TODO: ���� �����ֱ� �Լ� ȣ��
			DisplayMap(map, user_x, user_y);
			cout << "���� HP : " << my_user.GetHP() << "  ";
		}
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		// �������� �����ߴ��� üũ
		bool finish = CheckGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}

	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void DisplayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ����
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool CheckXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool CheckGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ�
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// ������ ��ġ�� �ִ� �������� ����ϰ� �ش� ���� hp�� �����ϴ� �Լ�
void CheckState(int map[][mapX], int user_x, int user_y, User& check) {
	if (map[user_y][user_x] == 2) {
		check.DecreaseHP(2);
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
	}
	else if (map[user_y][user_x] == 3) {
		check.IncreaseHP(2);
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;
	}
	else if (map[user_y][user_x] == 1) {
		cout << "�������� �ֽ��ϴ�." << endl;
	}
	return;
}

bool CheckUser(User check) {
	if (check.GetHP() > 0) {
		return true;
	}
	else {
		return false;
	}
}