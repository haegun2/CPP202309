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
	std::cout << "�����մϴ�" << endl;
}

void Magician::DoAttack() {
	std::cout << "���� ���" << endl;
}

void Warrior::DoAttack() {
	std::cout << "���� ���" << endl;
}