#pragma once
#include <iostream>
#include <string>

using namespace std;

class User {
private:
	int hp;

public:
	User() {hp = 20;}
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);
	int GetHP();
};