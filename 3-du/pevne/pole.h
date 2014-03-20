#ifndef POLE_H
#define POLE_H

#include <ostream>
#include <cassert>

const unsigned int N = 3;

class Pole
{
public:
	unsigned int velikost();

	void nastavPrvek(unsigned int index, double hodnota);
	double zjistiPrvek(unsigned int index);

	void vypis();

	double &operator[](unsigned int index)             { assert(index < N); return m_data[index]; }
	const double &operator[](unsigned int index) const { assert(index < N); return m_data[index]; }
	
private:
	double m_data[N];
};

std::ostream &operator<<(std::ostream &proud, const Pole &pole);

#endif