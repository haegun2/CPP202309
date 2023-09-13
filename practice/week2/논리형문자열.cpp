#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1 = "good";
	string s2 = "bad";
	bool b = (s1 == s2);
	cout << b << endl;
	//s1이랑 s2가 같으면 b를 출력해서 트루를 내놓겠다는 건데 s1이랑 s2랑 다름!

	s2 = "good";
	b = (s1 == s2);
	cout << b << endl;
	//s2를 맞춰주니 이제 트루가 뜸
}