#ifndef ABSTRAKTNI_POLE_H_INCLUDED
#define ABSTRAKTNI_POLE_H_INCLUDED

#include <ostream>

// Deklarace tridy AbstraktniPole - abstraktni bazova trida pro pole
template<typename T>
class AbstraktniPole
{
public:
	virtual ~AbstraktniPole() {}

	virtual unsigned int velikost() const = 0;

	virtual T &operator[](unsigned int index) = 0;
	virtual const T &operator[](unsigned int index) const = 0;
	
	void vypln (T hodnota)
	{
		for (unsigned int i=0; i < velikost(); i++) {
			(*this)[i] = hodnota;
		}	

	}
	
};


template<typename T>
std::ostream &operator<<(std::ostream &proud, const AbstraktniPole<T> &pole)
{
	for (unsigned int i = 0; i < pole.velikost(); i++)
		proud << pole[i] << " ";

	return proud;
}


#endif
