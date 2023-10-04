#include <iostream>
#include <string>
using namespace std;

int main() {

	const int STUDENT = 5;
	const int SUBJECT = 3; //과목수와 학생수를 상수로 지정
	int scores[STUDENT][SUBJECT];
	string studentNames[STUDENT] //학생이름 배열에 각각 이름을 지정
		= { "영수", "영희", "철수", "미미", "쥬쥬" };
	string subjectNames[SUBJECT] //과목명 배열에 과목명을 지정
		= { "수학", "영어", "CPP" };

	for (int i = 0; i < STUDENT; i++) { //for문을 통해서 학생 명을 차례대로 출력하면서
		cout << studentNames[i]
			<< "의 성적을 하나씩 입력하세요." << endl;
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":"; //과목명도 하나씩 출력하고 입력받아서
			cin >> scores[i][j]; // 점수 배열에 저장
		}
	}

	for (int i = 0; i < STUDENT; i++) { //학생명을 순서대로 출력
		cout << studentNames[i] << "의 평균 점수는 ";
		double sum = 0;
		double average = 0;
		for (int j = 0; j < SUBJECT; j++) {//학생에 따른 j값 즉 과목점수를 순서대로 합산
			sum += scores[i][j];
		}
		average = sum / SUBJECT;//평균을 내서 average변수에 저장
		cout << average << "입니다" << endl;//평균점수를 출력
	}
	return 0;
}