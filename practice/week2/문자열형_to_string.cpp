#include <iostream>
#include <string>
using namespace std;

int main()
{

	string s1 = "사과";
	string s2;
	//s2 = s1+ " " +10 + "개"; 는 안됨!
	s2 = s1 + "" + to_string(10) + "개";
	//쓰던 자료형을 쓰는거라서 문자열 쓰던곳에 10 쓰면 에러남 그래서 투스트링으로 숫자형이라고 알려주는 듯!!
	cout << s2 << endl;
}