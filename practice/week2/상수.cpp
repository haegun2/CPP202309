#include <iostream>
#define PI 3.14159265359
using namespace std;

int main()
{
	int income = 1000;
	const double TAX_RATE = 0.25;
	income = income - TAX_RATE * income;

	double x = 100;
	x = x * PI;

	cout << x << endl;
	return 0;
}
// 복습하면서 다시 공부하겠습니다.