#pragma once
#include <iostream>
#include <string>

using namespace std;

class User {
public:
	int hp;

	void DecreaseHP(int dec_hp);
	int GetHP();
};