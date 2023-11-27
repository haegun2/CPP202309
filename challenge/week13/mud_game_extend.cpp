#include "user.h"

using namespace std;

//맵 크기를 상수로 정의
const int mapX = 5;
const int mapY = 5;

int turn = 0; //누구 차례인지 나타내기 위한 변수
char current_user = 'M'; //누가 움직이고 있는지 나타내기 위한 변수 (M과 W)

// 사용자 정의 함수 : 함수원형을 선언
bool CheckXY(int user_x, int mapX, int user_y, int mapY);
void DisplayMap(int map[][mapX], int user_x, int user_y);
bool CheckGoal(int map[][mapX], int user_x, int user_y);
void CheckState(int map[][mapX], int user_x, int user_y, User& check);
bool CheckUser(User check);

// 메인  함수
int main() {
	Magician magi{};//(마법사 유저 M 선턴)
	Warrior warr{};//(전사 유저 w 후턴)

	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
							{1, 0, 0, 2, 0},
							{0, 0, 0, 0, 0},
							{0, 2, 3, 0, 0},
							{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int magi_x = 0; // 법사 가로 번호
	int magi_y = 0; // 법사 세로 번호
	int warr_x = 0; // 전사 가로 번호
	int warr_y = 0; // 전사 세로 번호


	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		switch (turn % 2) {
		case 0:
			current_user = 'M';
			break;
		case 1:
			current_user = 'W';
			break;
		}
		cout << turn % 3 + 1 << "번 유저(" << current_user << ")의 차례입니다. -> ";

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (current_user = 'M') {

			if (user_input == "상") {
				// 위로 한 칸 올라가기
				magi_y -= 1;
				bool inMap = CheckXY(magi_x, mapX, magi_y, mapY);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					magi_y += 1;
				}
				else {
					cout << "위로 한 칸 올라갑니다." << endl;
					DisplayMap(map, magi_x, magi_y);
					magi.DecreaseHP(1);
					CheckState(map, magi_x, magi_y, magi);
					if (CheckUser(magi) == false) {
						cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
						cout << "게임을 종료합니다." << endl;
						break;
					}
					cout << "현재 HP : " << magi.GetHP() << "  ";
				}
			}

			else if (user_input == "하") {
				// TODO: 아래로 한 칸 내려가기
				magi_y += 1;
				bool inMap = CheckXY(magi_x, mapX, magi_y, mapY);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					magi_y -= 1;
				}
				else {
					cout << "위로 한 칸 내려갑니다." << endl;
					DisplayMap(map, magi_x, magi_y);
					magi.DecreaseHP(1);
					CheckState(map, magi_x, magi_y, magi);
					if (CheckUser(magi) == false) {
						cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
						cout << "게임을 종료합니다." << endl;
						break;
					}
					cout << "현재 HP : " << magi.GetHP() << "  ";
				}
			}
			else if (user_input == "좌") {
				// TODO: 왼쪽으로 이동하기
				magi_x -= 1;
				bool inMap = CheckXY(magi_x, mapX, magi_y, mapY);

				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					magi_x += 1;
				}
				else {
					cout << "왼쪽으로 이동합니다." << endl;
					DisplayMap(map, magi_x, magi_y);
					magi.DecreaseHP(1);
					CheckState(map, magi_x, magi_y, magi);
					if (CheckUser(magi) == false) {
						cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
						cout << "게임을 종료합니다." << endl;
						break;
					}
					cout << "현재 HP : " << magi.GetHP() << "  ";
				}
			}
			else if (user_input == "우") {
				// TODO: 오른쪽으로 이동하기
				magi_x += 1;
				bool inMap = CheckXY(magi_x, mapX, magi_y, mapY);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					magi_x -= 1;
				}
				else {
					cout << "오른쪽으로 이동합니다." << endl;
					DisplayMap(map, magi_x, magi_y);
					magi.DecreaseHP(1);
					CheckState(map, magi_x, magi_y, magi);
					if (CheckUser(magi) == false) {
						cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
						cout << "게임을 종료합니다." << endl;
						break;
					}
					cout << "현재 HP : " << magi.GetHP() << "  ";
				}
			}

			else if (user_input == "지도") {
				// TODO: 지도 보여주기 함수 호출
				DisplayMap(map, magi_x, magi_y);
				cout << "현재 HP : " << magi.GetHP() << "  ";
			}
			else if (user_input == "종료") {
				cout << "종료합니다.";
				break;
			}
			else {
				cout << "잘못된 입력입니다." << endl;
				continue;
			}

			// 목적지에 도달했는지 체크
			bool finish = CheckGoal(map, magi_x, magi_y);
			if (finish == true) {
				cout << "목적지에 도착했습니다! 축하합니다!" << endl;
				cout << "게임을 종료합니다." << endl;
				break;
			}
		}

		if (current_user = 'W') {

			if (user_input == "상") {
				// 위로 한 칸 올라가기
				warr_y -= 1;
				bool inMap = CheckXY(warr_x, mapX, warr_y, mapY);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					warr_y += 1;
				}
				else {
					cout << "위로 한 칸 올라갑니다." << endl;
					DisplayMap(map, warr_x, warr_y);
					warr.DecreaseHP(1);
					CheckState(map, warr_x, warr_y, warr);
					if (CheckUser(warr) == false) {
						cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
						cout << "게임을 종료합니다." << endl;
						break;
					}
					cout << "현재 HP : " << warr.GetHP() << "  ";
				}
			}

			else if (user_input == "하") {
				// TODO: 아래로 한 칸 내려가기
				warr_y += 1;
				bool inMap = CheckXY(warr_x, mapX, warr_y, mapY);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					warr_y -= 1;
				}
				else {
					cout << "위로 한 칸 내려갑니다." << endl;
					DisplayMap(map, warr_x, warr_y);
					warr.DecreaseHP(1);
					CheckState(map, warr_x, warr_y, warr);
					if (CheckUser(warr) == false) {
						cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
						cout << "게임을 종료합니다." << endl;
						break;
					}
					cout << "현재 HP : " << warr.GetHP() << "  ";
				}
			}
			else if (user_input == "좌") {
				// TODO: 왼쪽으로 이동하기
				warr_x -= 1;
				bool inMap = CheckXY(warr_x, mapX, warr_y, mapY);

				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					warr_x += 1;
				}
				else {
					cout << "왼쪽으로 이동합니다." << endl;
					DisplayMap(map, warr_x, warr_y);
					warr.DecreaseHP(1);
					CheckState(map, warr_x, warr_y, warr);
					if (CheckUser(warr) == false) {
						cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
						cout << "게임을 종료합니다." << endl;
						break;
					}
					cout << "현재 HP : " << warr.GetHP() << "  ";
				}
			}
			else if (user_input == "우") {
				// TODO: 오른쪽으로 이동하기
				warr_x += 1;
				bool inMap = CheckXY(warr_x, mapX, warr_y, mapY);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					warr_x -= 1;
				}
				else {
					cout << "오른쪽으로 이동합니다." << endl;
					DisplayMap(map, warr_x, warr_y);
					warr.DecreaseHP(1);
					CheckState(map, warr_x, warr_y, warr);
					if (CheckUser(warr) == false) {
						cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
						cout << "게임을 종료합니다." << endl;
						break;
					}
					cout << "현재 HP : " << warr.GetHP() << "  ";
				}
			}

			else if (user_input == "지도") {
				// TODO: 지도 보여주기 함수 호출
				DisplayMap(map, warr_x, warr_y);
				cout << "현재 HP : " << warr.GetHP() << "  ";
			}
			else if (user_input == "종료") {
				cout << "종료합니다.";
				break;
			}
			else {
				cout << "잘못된 입력입니다." << endl;
				continue;
			}

			// 목적지에 도달했는지 체크
			bool finish = CheckGoal(map, warr_x, warr_y);
			if (finish == true) {
				cout << "목적지에 도착했습니다! 축하합니다!" << endl;
				cout << "게임을 종료합니다." << endl;
				break;
			}
		}
	
	}
	return 0;
}

// 지도와 사용자 위치 출력하는 함수
void DisplayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool CheckXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool CheckGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 유저의 위치에 있는 아이템을 출력하고 해당 값을 hp에 적용하는 함수
void CheckState(int map[][mapX], int user_x, int user_y, User& check) {
	if (map[user_y][user_x] == 2) {
		check.DecreaseHP(2);
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
	}
	else if (map[user_y][user_x] == 3) {
		check.IncreaseHP(2);
		cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
	}
	else if (map[user_y][user_x] == 1) {
		cout << "아이템이 있습니다." << endl;
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