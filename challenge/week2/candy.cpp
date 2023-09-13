#include <iostream>
#include <string>
using namespace std;

int main()
{
	string money;
	string cost;
	cout << "현재 가지고 있는 돈:" << endl;
	cin >> money;
	cout << "캔디의 가격" << endl;
	cin >> cost;
	cout << "최대로 살 수 있는 캔디=" << money / cost << endl;
	cout << "캔디 구입 후 남은 돈=" << money // cost << endl;

		return 0;
}