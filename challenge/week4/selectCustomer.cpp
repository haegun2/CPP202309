#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople = 3; // 상수선언 해버렸음
	//cout << "총 고객의 수를 입력하라: ";
	//cin >> maxPeople;
	string names[maxPeople]; //배열로 상수만큼의 칸을 저장 밑도 동일
	int ages[maxPeople];

	for (int i = 0; i < maxPeople; i++) { //for문으로 상수만큼의 고객 이름과 나이를 각각 배열에 저장
		cout << "사람" << i + 1 << "의 이름 : ";
		cin >> names[i];
		cout << "사람" << i + 1 << "의 나이 : ";
		cin >> ages[i];
	}

	int ageThreshold; //찾고자 하는 나이값을 상수로 저장
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
	cin >> ageThreshold;

	int oldman = 0; //맨 마지막 if문을 위하여 쉽게 상수로 저장함
	cout << ageThreshold << "세 이상인 고객들 : \n";

	for (int i = 0; i< maxPeople; i++)
		if (ages[i] >= ageThreshold) { // 만약 나이가 이상이라면
			cout << names[i] << "(" << ages[i] << "세)\n"; //고객의 이름과 나이를 출력
			oldman++;//있으면 oldman 상수가 올라감
	}
	if (oldman == 0) {// if문으로 전에 지정했던 oldman이 올라간 적이 없으면 밑의 문구를 출력
		cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다.";
	}

	return 0;
}