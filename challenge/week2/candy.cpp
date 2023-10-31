#include <iostream>
#include <string>
using namespace std;

int main()
{
	//돈과 가격, 합을 구할 변수를 추가
	int money;
	int cost;
	int sum1;
	int sum2;

	//사용자의 현재 잔액을 물어보아 money 변수에 입력하고
	cout << "현재 가지고 있는 돈:";
	cin >> money;
	//캔디의 가격을 물어봐 cost에 저장
	cout << "캔디의 가격:";
	cin >> cost;

	//나누기를 통하여 몫을 구해 몇개 인지, 나머지를 통해 남은 돈은 얼마인지 계산 
	sum1 = money / cost;
	sum2 = money % cost;

	//결과 값을 출력
	cout << "최대로 살 수 있는 캔디=" << sum1 << endl;
	cout << "캔디 구입 후 남은 돈=" << sum2 << endl;

}
