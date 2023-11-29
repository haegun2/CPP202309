#include<iostream>
#include<vector>
using namespace std;

class Animal {
public:
	virtual void speak() { cout << "Animal speak()" << endl; }
};

class Dog : public Animal {
public:
	int age;
	void speak() { cout << "港港" << endl; }
};

class Cat : public Animal {
public:
	void speak() { cout << "具克" << endl; }
};

int main() {
	Animal* a1 = new Dog();
	a1->speak();

	Animal* a2 = new Cat();
	a2->speak();

	Animal* a3 = new Animal();
	a3->speak();

	delete a1, a2, a3;

}