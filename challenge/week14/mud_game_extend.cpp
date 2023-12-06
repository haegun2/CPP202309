#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

int turn = 0; //���� �������� ����
char current_user = 'M'; //���� m ����. ������ m�� w

//�Լ�����
bool CheckXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(int map[][mapX], int a1, int a2, int b1, int b2);
bool CheckGoal(int map[][mapX], int user_x, int user_y);
void CheckState(int map[][mapX], int user_x, int user_y, User& check);
bool CheckUser(User check);


int main() {
	Magician magi{};//(������ ���� M ����)
	Warrior warr{};//(���� ���� w ����)
	
	int map[mapY][mapX];
	ifstream is{ "map.txt" };
	if (!is) { throw runtime_error("������ ���� �� �����ϴ�."); }
	while (is) {
		for (int i = 0; i < mapY; i++) {
			for (int j = 0; j < mapX; j++) {
				is >> map[i][j];
			}
		}
	}
			
	try {
		// ���� ���� 
		while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

			switch (turn % 2) {
			case 0:
				current_user = 'M';
				break;
			case 1:
				current_user = 'W';
				break;
			}
			cout << turn % 2 + 1 << "�� ����(" << current_user << ")�� �����Դϴ�. -> ";

			// ������� �Է��� ������ ����
			string user_input = "";

			cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
			cin >> user_input;

			if (current_user == 'M') {

				// �������� �����ߴ��� üũ
				bool finishm1 = CheckGoal(map, magi.x, magi.y);
				if (finishm1 == true) {
					cout << "�÷��̾�� �������� ������ �����Դϴ�!" << endl;
					cout << "���� �����մϴ�." << endl;
					turn++;
					DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
					continue;
				}

				if (user_input == "��") {
					// ���� �� ĭ �ö󰡱�
					magi.y -= 1;
					bool inMap = CheckXY(magi.x, mapX, magi.y, mapY);
					if (inMap == false) {
						cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
						magi.y += 1;
					}
					else {
						cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
						DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
						magi.DecreaseHP(1);
						CheckState(map, magi.x, magi.y, magi);
						if (CheckUser(magi) == false) {
							cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
							cout << "������ �����մϴ�." << endl;
							break;
						}
						cout << current_user << "�� ���� HP : " << magi.GetHP() << endl;
						turn++;
					}
				}

				else if (user_input == "��") {
					// TODO: �Ʒ��� �� ĭ ��������
					magi.y += 1;
					bool inMap = CheckXY(magi.x, mapX, magi.y, mapY);
					if (inMap == false) {
						cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
						magi.y -= 1;
					}
					else {
						cout << "���� �� ĭ �������ϴ�." << endl;
						DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
						magi.DecreaseHP(1);
						CheckState(map, magi.x, magi.y, magi);
						if (CheckUser(magi) == false) {
							cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
							cout << "������ �����մϴ�." << endl;
							break;
						}
						cout << current_user << "�� ���� HP : " << magi.GetHP() << endl;
						turn++;
					}
				}
				else if (user_input == "��") {
					// TODO: �������� �̵��ϱ�
					magi.x -= 1;
					bool inMap = CheckXY(magi.x, mapX, magi.y, mapY);

					if (inMap == false) {
						cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
						magi.x += 1;
					}
					else {
						cout << "�������� �̵��մϴ�." << endl;
						DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
						magi.DecreaseHP(1);
						CheckState(map, magi.x, magi.y, magi);
						if (CheckUser(magi) == false) {
							cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
							cout << "������ �����մϴ�." << endl;
							break;
						}
						cout << current_user << "�� ���� HP : " << magi.GetHP() << endl;
						turn++;
					}
				}
				else if (user_input == "��") {
					// TODO: ���������� �̵��ϱ�
					magi.x += 1;
					bool inMap = CheckXY(magi.x, mapX, magi.y, mapY);
					if (inMap == false) {
						cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
						magi.x -= 1;
					}
					else {
						cout << "���������� �̵��մϴ�." << endl;
						DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
						magi.DecreaseHP(1);
						CheckState(map, magi.x, magi.y, magi);
						if (CheckUser(magi) == false) {
							cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
							cout << "������ �����մϴ�." << endl;
							break;
						}
						cout << current_user << "�� ���� HP : " << magi.GetHP() << endl;
						turn++;
					}
				}

				else if (user_input == "����") {
					// TODO: ���� �����ֱ� �Լ� ȣ��
					DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
					cout << current_user << "�� ���� HP : " << magi.GetHP() << endl;
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
				bool finishm2 = CheckGoal(map, magi.x, magi.y);
				if (finishm2 == true) {
					cout << "�÷��̾�� �������� ������ �����Դϴ�!" << endl;
					cout << "���� �����մϴ�." << endl;
					turn++;
					DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
					continue;
				}
			}

			if (current_user == 'W') {

				bool finishw1 = CheckGoal(map, warr.x, warr.y);
				if (finishw1 == true) {
					cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
					cout << "������ �����մϴ�." << endl;
					turn++;
					DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
					continue;
				}

				if (user_input == "��") {
					// ���� �� ĭ �ö󰡱�
					warr.y -= 1;
					bool inMap = CheckXY(warr.x, mapX, warr.y, mapY);
					if (inMap == false) {
						cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
						warr.y += 1;
					}
					else {
						cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
						DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
						warr.DecreaseHP(1);
						CheckState(map, warr.x, warr.y, warr);
						if (CheckUser(warr) == false) {
							cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
							cout << "������ �����մϴ�." << endl;
							break;
						}
						cout << current_user << "�� ���� HP : " << warr.GetHP() << endl;
						turn++;
					}
				}

				else if (user_input == "��") {
					// TODO: �Ʒ��� �� ĭ ��������
					warr.y += 1;
					bool inMap = CheckXY(warr.x, mapX, warr.y, mapY);
					if (inMap == false) {
						cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
						warr.y -= 1;
					}
					else {
						cout << "���� �� ĭ �������ϴ�." << endl;
						DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
						warr.DecreaseHP(1);
						CheckState(map, warr.x, warr.y, warr);
						if (CheckUser(warr) == false) {
							cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
							cout << "������ �����մϴ�." << endl;
							break;
						}
						cout << current_user << "�� ���� HP : " << warr.GetHP() << endl;
						turn++;
					}
				}
				else if (user_input == "��") {
					// TODO: �������� �̵��ϱ�
					warr.x -= 1;
					bool inMap = CheckXY(warr.x, mapX, warr.y, mapY);

					if (inMap == false) {
						cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
						warr.x += 1;
					}
					else {
						cout << "�������� �̵��մϴ�." << endl;
						DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
						warr.DecreaseHP(1);
						CheckState(map, warr.x, warr.y, warr);
						if (CheckUser(warr) == false) {
							cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
							cout << "������ �����մϴ�." << endl;
							break;
						}
						cout << current_user << "�� ���� HP : " << warr.GetHP() << endl;
						turn++;
					}
				}
				else if (user_input == "��") {
					// TODO: ���������� �̵��ϱ�
					warr.x += 1;
					bool inMap = CheckXY(warr.x, mapX, warr.y, mapY);
					if (inMap == false) {
						cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
						warr.x -= 1;
					}
					else {
						cout << "���������� �̵��մϴ�." << endl;
						DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
						warr.DecreaseHP(1);
						CheckState(map, warr.x, warr.y, warr);
						if (CheckUser(warr) == false) {
							cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�." << endl;
							cout << "������ �����մϴ�." << endl;
							break;
						}
						cout << current_user << "�� ���� HP : " << warr.GetHP() << endl;
						turn++;
					}
				}

				else if (user_input == "����") {
					// TODO: ���� �����ֱ� �Լ� ȣ��
					DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
					cout << current_user << "�� ���� HP : " << warr.GetHP() << endl;
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
				bool finishw2 = CheckGoal(map, warr.x, warr.y);
				if (finishw2 == true) {
					cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
					cout << "������ �����մϴ�." << endl;
					turn++;
					DisplayMap(map, magi.x, magi.y, warr.x, warr.y);
					continue;
				}
			}

		}
	}
	catch (exception& e) { cout << "���� :"<< e.what() << endl; }
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void DisplayMap(int map[][mapX], int a1, int a2, int b1, int b2) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == a2 && j == a1 && i == b2 && j == b1) { cout << " M & W|"; }
			else if (i == a2 && j == a1) { cout << " Magi |"; }
			else if (i == b2 && j == b1) { cout << " Warr |"; }
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