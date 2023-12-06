#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <exception>

using namespace std;

class User {
private:
	int hp;

public:
	int x, y;
	User() { hp = 20, x = 0, y = 0; }
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);

	int GetHP();
	void DoAttack();
};

class Magician : public User {
	void DoAttack();
};

class Warrior : public User {
	void DoAttack();
};