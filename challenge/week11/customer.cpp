#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int max_people, age;
	string name;
	vector<string> names;
	vector<int> ages;

	cout << "총 고객의 수를 입력하라: ";
	cin >> max_people;


	for (int i = 0; i < max_people; i++) {
		cout << "사람" << i + 1 << "의 이름 : ";
		cin >> name;
		cout << "사람" << i + 1 << "의 나이 : ";
		cin >> age;
		names.push_back(name);
		ages.push_back(age);
	}

	int age_threshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
	cin >> age_threshold;

	int oldman = 0;
	cout << age_threshold << "세 이상인 고객들 : \n";

	for (int i = 0; i < max_people; i++)
		if (ages[i] >= age_threshold) {
			cout << names[i] << "(" << ages[i] << "세)\n";
			oldman++;
		}

	if (oldman == 0) {
		cout << age_threshold << "이상의 나이를 가진 고객이 없습니다.";
	}

	return 0;
}