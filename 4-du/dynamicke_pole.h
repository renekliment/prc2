#ifndef DYNAMICKE_POLE_H_INCLUDED
#define DYNAMICKE_POLE_H_INCLUDED

#include <ostream>
#include <cassert>


class DynamickePole
{
public:
	explicit DynamickePole(unsigned int velikost);
	DynamickePole(const DynamickePole &pole);
	~DynamickePole();

	DynamickePole &operator=(DynamickePole pravaStrana);

	unsigned int velikost() const                      { return m_velikost; }

	bool &operator[](unsigned int index)             { assert(index < velikost()); return m_data[index]; }
	const bool &operator[](unsigned int index) const { assert(index < velikost()); return m_data[index]; }

private:
	unsigned int m_velikost;
	bool *m_data;
};


std::ostream &operator<<(std::ostream &proud, const DynamickePole &pole);


#endif
