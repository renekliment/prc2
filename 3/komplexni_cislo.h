#ifndef KOMPLEXNI_CISLO_H_INCLUDED
#define KOMPLEXNI_CISLO_H_INCLUDED

#include <ostream>


class KomplexniCislo
{
public:
	KomplexniCislo(double re = 0, double im = 0): m_re(re), m_im(im) {}

	double zjistiRe() const { return m_re; }
	double zjistiIm() const { return m_im; }

	KomplexniCislo &operator+=(KomplexniCislo z);
	KomplexniCislo &operator-=(KomplexniCislo z);
	KomplexniCislo &operator*=(KomplexniCislo z);
	KomplexniCislo &operator/=(KomplexniCislo z);

	KomplexniCislo &operator++();         // ++z
	const KomplexniCislo operator++(int); // z++

	KomplexniCislo &operator--();         // --z
	const KomplexniCislo operator--(int); // z--

	const KomplexniCislo operator+() const; // Unarni plus (identita)
	const KomplexniCislo operator-() const; // Unarni minus (opacna hodnota)

private:
	double m_re, m_im;
};


bool operator==(KomplexniCislo z1, KomplexniCislo z2);
bool operator!=(KomplexniCislo z1, KomplexniCislo z2);
const KomplexniCislo operator+(KomplexniCislo z1, KomplexniCislo z2);
const KomplexniCislo operator-(KomplexniCislo z1, KomplexniCislo z2);
const KomplexniCislo operator*(KomplexniCislo z1, KomplexniCislo z2);
const KomplexniCislo operator/(KomplexniCislo z1, KomplexniCislo z2);

std::ostream &operator<<(std::ostream &proud, KomplexniCislo z);


#endif
