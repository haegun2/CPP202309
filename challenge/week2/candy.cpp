#include <iostream>
#include <string>
using namespace std;

int main()
{
	int money;
	int cost;
	int sum1;
	int sum2;
	cout << "현재 가지고 있는 돈:";
	cin >> money;
	cout << "캔디의 가격:";
	cin >> cost;

	sum1 = money / cost;
	sum2 = money % cost;

	cout << "최대로 살 수 있는 캔디=" << sum1 << endl;
	cout << "캔디 구입 후 남은 돈=" << sum2 << endl;

}
