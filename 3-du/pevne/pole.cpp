#include <iostream>

#include "pole.h"

using namespace std;

unsigned int Pole::velikost()
{
	return N;
}

void Pole::nastavPrvek(unsigned int index, double hodnota)
{
	m_data[index] = hodnota;
}

double Pole::zjistiPrvek(unsigned int index)
{
	return m_data[index];
}

void Pole::vypis()
{
	for (unsigned int i=0; i < N; i++) {
		cout << m_data[i] << endl;
	}
}

ostream &operator<<(ostream &proud, const Pole &pole)
{
	for (unsigned int i = 0; i < N; i++) {
		proud << pole[i] << " ";
	}
	
	proud << endl;
	
	return proud;
}