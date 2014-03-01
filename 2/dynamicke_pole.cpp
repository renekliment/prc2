#include <iostream>
#include "dynamicke_pole.h"

using namespace std;


DynamickePole::DynamickePole(unsigned int size)
: m_size(size) // pořadí inicializace je takové, jaké je v deklaraci třídy
{
	//m_size = size;

	m_data = new double[m_size];

	for (unsigned int i = 0; i < m_size; i++) // Volame metodu v konstruktoru a funguje to!
		m_data[i] = 0;
}

DynamickePole::DynamickePole(const DynamickePole &array)
{
	m_size = array.velikost();

	m_data = new double[m_size];

	for (unsigned int i = 0; i < m_size; i++) // Volame metodu v konstruktoru a funguje to!
		m_data[i] = array.zjistiPrvek(i);
}

DynamickePole &DynamickePole::operator=(DynamickePole array) // zrusili jsme predavani referenci a dali kopii
{
	/*if (&array == this) {
		return *this;
	}

	delete[] m_data;

	m_size = array.velikost();

	m_data = new double[m_size];

	for (unsigned int i = 0; i < m_size; i++) // Volame metodu v konstruktoru a funguje to!
		m_data[i] = array.zjistiPrvek(i);
*/
/*
	double *data = new double[array.m_size];
	for (unsigned int i=0; i < array.velikost(); i++)
		data[i] = array.m_data[i];


	delete[] m_data;

	m_size = array.velikost();
	m_data = data;
*/

	swap(m_size, array.m_size);
	swap(m_data, array.m_data);

	return *this;
}

DynamickePole::~DynamickePole()
{
	delete[] m_data;
}


void DynamickePole::nastavPrvek(unsigned int index, double hodnota)
{
	if (index < velikost())
		m_data[index] = hodnota;
}

double DynamickePole::zjistiPrvek(unsigned int index) const
{
	if (index < velikost())
		return m_data[index];

	return 0;
}

void DynamickePole::vypis() const
{
	for (unsigned int i = 0; i < velikost(); i++)
		cout << zjistiPrvek(i) << " ";

	cout << endl;
}
