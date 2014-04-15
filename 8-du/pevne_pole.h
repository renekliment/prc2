#ifndef PEVNE_POLE_H_INCLUDED
#define PEVNE_POLE_H_INCLUDED

#include <cassert>
#include "abstraktni_pole.h"


const unsigned int N = 3;

class PevnePole : public AbstraktniPole<double>
{
public:
	PevnePole();
	virtual ~PevnePole() {}

	virtual unsigned int velikost() const { return N; }

	virtual double &operator[](unsigned int index)             { assert(index < velikost()); return m_data[index]; }
	virtual const double &operator[](unsigned int index) const { assert(index < velikost()); return m_data[index]; }

private:
	double m_data[N];
};


#endif
