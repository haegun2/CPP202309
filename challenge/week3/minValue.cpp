#include <iostream>
using namespace std;


int main() {

	int a, b, c, mini;

	cout << "3개의 정수를 입력하시오: ";
	cin >> a >> b >> c;

	if (a < b && a < c) //a가 b와 c보다 작으면 째깐이는 a
		mini = a;
	else if (b < a && b < c) //b가 a랑 c보다 작으면 b가 작은놈
		mini = b;
	else// 둘 다 아니면 c가 제일 작음
		mini = c;

	cout << "가장 작은 정수는" << mini << endl;
	return 0;

}