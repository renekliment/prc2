#ifndef POLE_H
#define POLE_H

const unsigned int N = 3;

class Pole
{
public:
	unsigned int velikost();

	void nastavPrvek(unsigned int index, double hodnota);
	double zjistiPrvek(unsigned int index);

	void vypis();

private:
	double m_data[N];

};

#endif