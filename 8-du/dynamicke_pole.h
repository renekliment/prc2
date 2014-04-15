#ifndef DYNAMICKE_POLE_H_INCLUDED
#define DYNAMICKE_POLE_H_INCLUDED

#include <cassert>
#include "abstraktni_pole.h"


template<typename T>
class DynamickePole : public AbstraktniPole<T>
{
public:
	explicit DynamickePole(unsigned int velikost);
	DynamickePole(const DynamickePole<T> &pole);
	virtual ~DynamickePole();

	DynamickePole<T> &operator=(DynamickePole<T> pravaStrana);

	virtual unsigned int velikost() const { return m_velikost; }

	virtual T &operator[](unsigned int index)             { assert(index < velikost()); return m_data[index]; }
	virtual const T &operator[](unsigned int index) const { assert(index < velikost()); return m_data[index]; }

private:
	unsigned int m_velikost;
	T *m_data;
};


template<typename T>
DynamickePole<T>::DynamickePole(unsigned int velikost)
: m_velikost(velikost), m_data(new T[m_velikost])
{
	for (unsigned int i = 0; i < m_velikost; i++)
		m_data[i] = 0;
}

template<typename T>
DynamickePole<T>::DynamickePole(const DynamickePole<T> &pole)
: m_velikost(pole.m_velikost), m_data(new T[pole.m_velikost])
{
	for (unsigned int i = 0; i < m_velikost; i++)
		m_data[i] = pole.m_data[i];
}

template<typename T>
DynamickePole<T>::~DynamickePole()
{
	delete[] m_data;
}

template<typename T>
DynamickePole<T> &DynamickePole<T>::operator=(DynamickePole<T> pravaStrana)
{
	std::swap(m_velikost, pravaStrana.m_velikost);
	std::swap(m_data, pravaStrana.m_data);

	return *this;
}


#endif
