#include<iostream>
using namespace std;
class Animal
{
public:
	virtual void sound() = 0;
};
class Cat : Animal{}; // Abstract either
class Tiger : Cat
{
public:
	void sound()override
	{
		cout << "RAAAAWR ROOOOOOOAR" << endl;
	}
};
class HomeCat : Cat
{
public:
	void sound()override
	{
		cout << "MEeeeEEEOoOoOW" << endl;
	}
};
void main()
{
	setlocale(LC_ALL, " ");
	//Animal dawg; Cat poopa;
	Tiger tiger;
	HomeCat cat;
	cout << "Tiger says: ";tiger.sound();
	cout << "Kitty says: ";cat.sound();
}