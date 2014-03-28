#include <iostream>
#include "seznam.h"

using namespace std;


int main()
{
	Seznam seznam;
	for (int i = 0; i < 10; i++)
		seznam.vlozNaZacatek(i);

	cout << "Vypis seznamu: " << seznam << endl;

	int data = 5;
	cout << "Hledani hodnoty " << data << " v seznamu: ";
	for (Seznam::Iterator iter = seznam.begin(); iter != seznam.end(); ++iter)
		if (*iter == data)
		{
			cout << "nalezena" << endl;

			data = 50;
			cout << "Vlozeni hodnoty " << data << " do seznamu za hodnotu " << *iter << endl;
			seznam.vlozZa(iter, data);
			cout << "Vypis seznamu: " << seznam << endl;

			cout << "Smazani hodnoty " << *iter << " ze seznamu" << endl;
			seznam.odstran(iter);

			cout << "Vypis seznamu: " << seznam << endl;
                        data = -314;
		}

	return 0;
}
