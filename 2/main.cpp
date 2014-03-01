#include <iostream>
#include "dynamicke_pole.h"

using namespace std;

double average(const DynamickePole &array)
{
	unsigned int size = array.velikost();

	if (!size) return 0;

	double sum = 0;

	unsigned int i;
	for (i=0; i < size; i++) {
		sum += array.zjistiPrvek(i);
	}

	return sum / size;
}

int main()
{
	DynamickePole x(3);
	x.nastavPrvek(0, -2.4);
	x.nastavPrvek(1, 10.0);
	cout << "x = ";
	x.vypis();

	// Kopirovani objektu
	DynamickePole y(x); // PevnePole y = x;
	cout << "y = ";
	y.vypis();

	// Prirazovani objektu
	x.nastavPrvek(2, 9999.0);
	//y = x;
	cout << "y = ";
	y.vypis();

	cout << "Average: " << average(x) << endl;

	return 0;
}
