#ifndef POLE_H
#define POLE_H

#include <ostream>
#include <cassert>

//const unsigned int N = 3;

template <typename T, int N>
class Pole
{
public:
	unsigned int velikost();

	void nastavPrvek(unsigned int index, T hodnota);
	T zjistiPrvek(unsigned int index);

	void vypis();

	T &operator[](unsigned int index)             { assert(index < N); return m_data[index]; }
	const T &operator[](unsigned int index) const { assert(index < N); return m_data[index]; }
	
private:
	T m_data[N];
};

template <typename T, int N>
std::ostream &operator<<(std::ostream &proud, const Pole<T, N> &pole);


template <typename T, int N>
unsigned int Pole<T, N>::velikost()
{
	return N;
}

template <typename T, int N>
void Pole<T, N>::nastavPrvek(unsigned int index, T hodnota)
{
	m_data[index] = hodnota;
}

template <typename T, int N>
T Pole<T, N>::zjistiPrvek(unsigned int index)
{
	return m_data[index];
}

template <typename T, int N>
void Pole<T, N>::vypis()
{
	for (unsigned int i=0; i < N; i++) {
		std::cout << m_data[i] << std::endl;
	}
}

template <typename T, int N>
std::ostream &operator<<(std::ostream &proud, const Pole<T, N> &pole)
{
	for (unsigned int i = 0; i < N; i++) {
		proud << pole[i] << " ";
	}
	
	proud << std::endl;
	
	return proud;
}

#endif