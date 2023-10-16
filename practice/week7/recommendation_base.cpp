#include <iostream>
using namespace std;

int main() {
	//유저 수와 아이템을 상수로 지정하고, 그것을 기반으로 하는 2차원 배열 userPreferences를 생성
	const int NUM_USERS = 3;
	const int NUM_ITEMS = 3;
	int userPreferences[NUM_USERS][NUM_ITEMS];

	//사용자와 항목 간의 선호도를 입력 받아 2차원 배열 초기화
	for (int i = 0; i < NUM_USERS; ++i) {
		//사용자 수에 따라서 차례대로 물어보고 그 값을 배열에 저장
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해):";
		for (int j = 0; j < NUM_USERS; ++j) {
			cin >> userPreferences[i][j];
		}
	}

	// 각 사용자에 대한 추천 항목 찾기
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}

		// 사용자에게 추천하는 항목 추천
		cout << "사용자" << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}

	return 0;
}