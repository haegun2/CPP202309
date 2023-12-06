#include "user.h"
using namespace std;

void User::DecreaseHP(int dec_hp) {
	hp -= dec_hp;
}

void User::IncreaseHP(int inc_hp) {
	hp += inc_hp;
}

int User::GetHP() {
	return hp;
}

void User::DoAttack() {
	std::cout << "공격합니다" << endl;
}

void Magician::DoAttack() {
	std::cout << "마법 사용" << endl;
}

void Warrior::DoAttack() {
	std::cout << "베기 사용" << endl;
}