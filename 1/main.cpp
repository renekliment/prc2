#include <iostream>

#include "pole.h"

using namespace std;

/*
void f (int &a)
{
	a++;
}
*/

int main ()
{
	/*
	int x = 5;

	f(x);

	cout << "hu: " << x << endl;
*/

	Pole arr;

	arr.nastavPrvek(0, 1.5);
	arr.nastavPrvek(1, 10);
	arr.nastavPrvek(2, -6.78);
	arr.vypis();

	return 0;
}