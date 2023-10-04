#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	const int numCell = 10; //상수 지정
	int numList[numCell][numCell]; //10x10의 배열을 생성

	
	for (int i = 0; i < numCell ; i++) { //i와 j값을 순차적으로 증가시키며 해당 배열에
		for (int j = 0; j < numCell; j++) {
			int elem = rand() % 1000;//0~999 사이의 랜덤 생성 값을 지정
			numList[i][j] = elem;
			cout << i << ", " << j << " : " << elem << endl; //해당 값을 차례대로 출력
		}
	}
	cout << endl;

	int max=0; //최대값 변수
	int maxI=0; //최대값의 i 값 변수
	int maxJ=0; // 최대값의 j값 변수
	for (int i = 0; i < numCell; i++) { //i를 증가시킴
		int j = 0; // j값 변수 지정 및 초기화
		for (auto var : numList[i]) { // numlist i 중에서 값을 순차적으로 var로 줌
			if (var > max) { // var 값이 max보다 크면
				max = var; //max값을 var로 바꿈!!
				maxI = i; //그리고 그때의 i,j 값을 저장
				maxJ = j;
			}
			j++; //맞든 아니든 한 회차 지날때마다 j값을 하나씩 증가
		}
	}

	cout << "가장 큰 값은" << max << "이고,";
	cout << "i와 j는 각각" << maxI << ", " << maxJ << "입니다." << endl; //출력 최대값과 i,j값
	cout << "검증결과: " << numList[maxI][maxJ] << endl; //좌표로 확인하면서 검증

	return 0;
}