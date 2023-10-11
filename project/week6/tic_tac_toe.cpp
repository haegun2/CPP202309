#include<iostream>
using namespace std;

int main() {
	const int numCell = 3;
	char board[numCell][numCell]{};
	int x, y; // 사용자에게 입력받을 x,y 좌표

	//보드판을 만들고 값으로 공백 설정
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	//게임하는 코드
	int k = 0;
	char currentUser = 'X'; //현재 유저의 돌을 저장하기 위한 문자
	while (true) {
		//1. 몇번 유저의 차례인지 출력
		switch (k % 2) { // 나머지를 0 1로
		case 0:
			cout << k % 2 + 1 << "번 유저(X)의 차례입니다 -> "; // 
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "번 유저(O)의 차례입니다 -> ";
			currentUser = 'O';
			break;
		}

		//2.유저에게 좌표입력받기
		cout << "(x,y) 좌표를 입력하세요: ";
		cin >> x >> y;

		//3.입력받은 좌표의 유효성 체크. 보드판 밖의 값이거나 이미 값이 있을 때
		if (x >= numCell || y >= numCell) {
			cout << x << "," << y << ":";
			cout << "x 와 y 둘 중 하나가 칸을 벗어납니다." << endl;
			continue;
		}
		if (board[x][y] != ' ') {
			cout << x << "," << y << ": 이미 돌이 차있습니다." << endl;
			continue;
		}

		//4.입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		//5.현재 보드판 출력

		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl; //맨 위 보드칸 그리기
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j]; //칸당 하나씩 그리고
				if (j == numCell - 1) {
					break; //마지막은  | 안그리고 탈출
				}
				cout << "  |";
			}
			cout << endl;
		}
		cout << "---|---|---" << endl; // 맨 밑칸 보드칸 드리기
		k++;

		//6.모든 칸이 찼으면 종료
		int checked = 0; //체크를 위한 변수를 만들고
		for (int i = 0; i < numCell; i++) { 
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') { // 빈칸이 있을때마다 변수 값을 추가!!
					checked++;
				}
			}
		}
		if (checked == 0) { //매번 반복으로 돌리면서 마지막에 체크가 더이상 추가되지 않으면
			cout << "모든 칸이 다 찼습니다. 종료합니다.<<endl";
			break; // 끝내고 반복문 탈출
		}

		//7. 승자 체크
		bool isWin = false; //승리 확인을 위한 변수

		for (int i = 0; i < numCell; i++) { // 각각 X와 Y 좌표의 i가 증가할 때 해당 줄의 모든 값이 현재유저 값이면 승리 확인
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "가로에 모두 돌이 놓였습니다!: ";
				isWin = true;
			}
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "세로에 모두 돌이 놓였습니다!: ";
				isWin = true;
			}
		}// 대각선의 모든 값이 현재 유저의 값일 때 유저값과 같으면 승리확인
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
			isWin = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
			isWin = true;
		}
		// 승리 확인을 위한 변수가 TRUE가 되면, 현재 유저의 승리를 출력
		if (isWin == true) {
			cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			cout << "종료합니다" << endl;
			break;
		}
	}
	return 0;
}