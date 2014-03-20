#include <iostream>
#include "array2D.h"

using namespace std;


Array2D::Array2D(unsigned int m, unsigned int n)
: m_size_m(m), m_size_n(n), m_data(new double[m*n])
{
	for (unsigned int i = 0; i < m_size_m * m_size_n; i++) {
		m_data[i] = 0;
	}
}

Array2D::Array2D(const Array2D &array)
: m_size_m(array.m_size_m), m_size_n(array.m_size_n), m_data(new double[array.m_size_m * array.m_size_n])
{
	for (unsigned int i = 0; i < m_size_m * m_size_n; i++)
		m_data[i] = array.m_data[i];
}

Array2D::~Array2D()
{
	delete[] m_data;
}

Array2D &Array2D::operator=(Array2D rhs) // Prava strana se predava kopii
{
	swap(m_size_m, rhs.m_size_m);
	swap(m_size_n, rhs.m_size_n);
	swap(m_data, rhs.m_data);

	return *this; // Kvuli zretezenemu prirazeni
}

void Array2D::set(unsigned int m, unsigned int n, double value)
{
	if (m < m_size_m && n < m_size_n)
		m_data[m*m_size_n + n] = value;
}

double Array2D::get(unsigned int m, unsigned int n) const
{
	if (m < m_size_m && n < m_size_n)
		return m_data[m*m_size_n + n];

	return 0;
}

void Array2D::print() const
{
	for (unsigned int i = 0; i < m_size_m * m_size_n; i++) {
		cout << m_data[i] << "\t";

		if ( (i + 1) % m_size_n == 0) {
			cout << endl;
		}
	}

	cout << endl;
}

void Array2D::fill(double value)
{
	for (unsigned int i = 0; i < m_size_m * m_size_n; i++) {
		m_data[i] = value;
	}
}
