#include<iostream>
using namespace std;

class RemoteControl {
public:
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
};

class Television : public RemoteControl {
public:
	void TurnOn()override { cout << "TV¸¦ ÄÕ´Ï´Ù." << endl; }
	void TurnOff()override { cout << "TV¸¦ ²ü´Ï´Ù." << endl; }
};

class Refrigerator : public RemoteControl {
public:
	void TurnOn()override { cout << "³ÃÀå°í¸¦ ÄÕ´Ï´Ù." << endl; }
	void TurnOff()override { cout << "³ÃÀå°í¸¦ ²ü´Ï´Ù." << endl; }
};

int main() {
	RemoteControl* remote_tv = new Television();
	RemoteControl* remote_rfg = new Refrigerator();

	remote_tv->TurnOn();
	remote_tv->TurnOff();
	remote_rfg->TurnOn();
	remote_rfg->TurnOff();

	delete remote_tv, remote_rfg;
}