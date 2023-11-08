#include <iostream>
using namespace std;

int main() {

	double f_temp;
	double c_temp;

	cout << "È­¾¾¿Âµµ: ";
	cin >> f_temp;

	c_temp = (5.0 / 9.0) * (f_temp - 32);

	cout << "¼·¾¾¿Âµµ= " << c_temp << endl;
	return 0;

}