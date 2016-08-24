#include <iostream>
#include "Source.h"
using namespace std;

class Damagable
{
public:
	virtual void TakeDamage();
	int Hp;
};
class Fighter : Damagable
{
public:
	void TakeDamage()
	{
		Hp -= 10;
	};
};
class Swordsman : Fighter
{
public:
	int Hp = 100;


};

int main()
{
	Swordsman jeff;
	cout << " Swordsman Jeff's HP is : "<< jeff.Hp << endl;
	jeff.TakeDamage;
	cout << " Swordsman Jeff's HP is now : " << jeff.Hp << endl;
	system("pause");
	return 0;
}
