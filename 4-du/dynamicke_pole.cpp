#include "dynamicke_pole.h"

using namespace std;


DynamickePole::DynamickePole(unsigned int velikost)
: m_velikost(velikost), m_data(new bool[m_velikost])
{
	for (unsigned int i = 0; i < m_velikost; i++)
		m_data[i] = 0;
}

DynamickePole::DynamickePole(const DynamickePole &pole)
: m_velikost(pole.m_velikost), m_data(new bool[pole.m_velikost])
{
	for (unsigned int i = 0; i < m_velikost; i++)
		m_data[i] = pole.m_data[i];
}

DynamickePole::~DynamickePole()
{
	delete[] m_data;
}

DynamickePole &DynamickePole::operator=(DynamickePole pravaStrana)
{
	swap(m_velikost, pravaStrana.m_velikost);
	swap(m_data, pravaStrana.m_data);

	return *this;
}


ostream &operator<<(ostream &proud, const DynamickePole &pole)
{
	for (unsigned int i = 0; i < pole.velikost(); i++)
		proud << pole[i] << " ";

	return proud;
}
