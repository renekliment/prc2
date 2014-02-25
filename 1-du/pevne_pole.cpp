#include <iostream>
#include "pevne_pole.h"

using namespace std;


PevnePole::PevnePole()
{
	for (unsigned int i = 0; i < velikost(); i++) // Volame metodu v konstruktoru a funguje to!
		m_data[i] = 0;
}

void PevnePole::nastavPrvek(unsigned int index, double hodnota)
{
	if (index < velikost())
		m_data[index] = hodnota;
}

double PevnePole::zjistiPrvek(unsigned int index) const
{
	if (index < velikost())
		return m_data[index];

	return 0;
}

void PevnePole::vypis() const
{
	for (unsigned int i = 0; i < velikost(); i++)
		cout << zjistiPrvek(i) << " ";

	cout << endl;
}
