#include <iostream>

#include "komplexni_cislo.h"

using namespace std;

int main (void)
{
	KomplexniCislo z1(1,2);
	KomplexniCislo z2(3,4);

	z1 += z2;

	cout << "Hu: " << z1 << endl;

	cout << "Hu: " << (z1 + z1) << endl;

	return 0;
}