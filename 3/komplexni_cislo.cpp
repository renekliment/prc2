#include "komplexni_cislo.h"

using namespace std;


KomplexniCislo &KomplexniCislo::operator+=(KomplexniCislo z)
{
	m_re += z.zjistiRe();
	m_im += z.zjistiIm();

	return *this;
}

KomplexniCislo &KomplexniCislo::operator-=(KomplexniCislo z)
{


	return *this;
}

KomplexniCislo &KomplexniCislo::operator*=(KomplexniCislo z)
{


	return *this;
}

KomplexniCislo &KomplexniCislo::operator/=(KomplexniCislo z)
{


	return *this;
}

KomplexniCislo &KomplexniCislo::operator++()
{
	m_re++;
	m_im++;

	return *this;
}

const KomplexniCislo KomplexniCislo::operator++(int)
{
	KomplexniCislo copy(*this);

	++(*this);

	return copy;
}

KomplexniCislo &KomplexniCislo::operator--()
{


	return *this;
}

const KomplexniCislo KomplexniCislo::operator--(int)
{

}

const KomplexniCislo KomplexniCislo::operator+() const
{

}

const KomplexniCislo KomplexniCislo::operator-() const
{

}

bool operator==(KomplexniCislo z1, KomplexniCislo z2)
{

}

bool operator!=(KomplexniCislo z1, KomplexniCislo z2)
{

}

const KomplexniCislo operator+(KomplexniCislo z1, KomplexniCislo z2)
{
	return (z1 += z2);
}

const KomplexniCislo operator-(KomplexniCislo z1, KomplexniCislo z2)
{

}

const KomplexniCislo operator*(KomplexniCislo z1, KomplexniCislo z2)
{

}

const KomplexniCislo operator/(KomplexniCislo z1, KomplexniCislo z2)
{

}


ostream &operator<<(ostream &proud, KomplexniCislo z)
{
	proud << z.zjistiRe();
	if (z.zjistiIm() > 0.0)
		proud << " + " << z.zjistiIm() << "i";
	else if (z.zjistiIm() < 0.0)
		proud << " - " << -z.zjistiIm() << "i";

	return proud;
}
