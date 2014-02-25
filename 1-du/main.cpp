#include <iostream>
#include "pevne_pole.h"

using namespace std;


// Funkce na prohozeni obsahu dvou promennych, argumenty se predavaji pomoci referenci
void swap(int &a, int &b)
{
	int pom = a;
	a = b;
	b = pom;
}

bool comparePevnePole (PevnePole &a, PevnePole &b)
{
	unsigned int size = a.velikost();

	if (b.velikost() != size) return false;

	for (unsigned int i=0; i < size; i++) {
		if (a.zjistiPrvek(i) != b.zjistiPrvek(i))
			return false;
	}

	return true;
}

int main()
{
	// Funkce swap()
	int a = 5, b = 10;
	cout << "Pred prohozenim: a = " << a << ", b = " << b << endl;
	swap(a, b);
	cout << "Po prohozeni: a = " << a << ", b = " << b << endl << endl;

	// Instancovani tridy - vznik objektu
	PevnePole x;
	x.nastavPrvek(0, -2.4);
	x.nastavPrvek(1, 10.0);
	cout << "x = ";
	x.vypis();

	// Kopirovani objektu
	PevnePole y(x); // PevnePole y = x;
	cout << "y = ";
	y.vypis();

	cout << "comparePevnePole result: " << (int)comparePevnePole(x, y) << endl;

	// Prirazovani objektu
	x.nastavPrvek(2, 9999.0);

	cout << "comparePevnePole result: " << (int)comparePevnePole(x, y) << endl;
	
	y = x;
	cout << "y = ";
	y.vypis();

	return 0;
}
