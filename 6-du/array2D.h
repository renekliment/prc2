#ifndef ARRAY2D_H_INCLUDED
#define ARRAY2D_H_INCLUDED

#include <cassert>

template <typename T>
class Array2D
{
public:
	explicit Array2D(unsigned int m, unsigned int n); // Konstruktor s parametrem
	Array2D(const Array2D &array);      // Kopirovaci konstruktor
	~Array2D();

	Array2D &operator=(Array2D rhs); // Prirazovaci operator

	unsigned int getSize_m() const { return m_size_m; }
	unsigned int getSize_n() const { return m_size_n; }

	void set(unsigned int m, unsigned int n, T value);
	T get(unsigned int m, unsigned int n) const;

	T &operator()(unsigned int m, unsigned int n) {
		assert(m < m_size_m && n < m_size_n);
		return m_data[m*m_size_n + n];
	}

	const T &operator()(unsigned int m, unsigned int n) const {
		assert(m < m_size_m && n < m_size_n);
		return m_data[m*m_size_n + n];
	}
	
	void print() const;

	void fill(T value);

private:
	unsigned int m_size_m, m_size_n;
	T *m_data;
};


template <typename T>
Array2D<T>::Array2D(unsigned int m, unsigned int n)
: m_size_m(m), m_size_n(n), m_data(new T[m*n])
{
	for (unsigned int i = 0; i < m_size_m * m_size_n; i++) {
		m_data[i] = 0;
	}
}

template <typename T>
Array2D<T>::Array2D(const Array2D &array)
: m_size_m(array.m_size_m), m_size_n(array.m_size_n), m_data(new T[array.m_size_m * array.m_size_n])
{
	for (unsigned int i = 0; i < m_size_m * m_size_n; i++)
		m_data[i] = array.m_data[i];
}

template <typename T>
Array2D<T>::~Array2D()
{
	delete[] m_data;
}

template <typename T>
Array2D<T> &Array2D<T>::operator=(Array2D<T> rhs) // Prava strana se predava kopii
{
	swap(m_size_m, rhs.m_size_m);
	swap(m_size_n, rhs.m_size_n);
	swap(m_data, rhs.m_data);

	return *this; // Kvuli zretezenemu prirazeni
}

template <typename T>
void Array2D<T>::set(unsigned int m, unsigned int n, T value)
{
	if (m < m_size_m && n < m_size_n)
		m_data[m*m_size_n + n] = value;
}

template <typename T>
T Array2D<T>::get(unsigned int m, unsigned int n) const
{
	if (m < m_size_m && n < m_size_n)
		return m_data[m*m_size_n + n];

	return 0;
}

template <typename T>
void Array2D<T>::print() const
{
	for (unsigned int i = 0; i < m_size_m * m_size_n; i++) {
		std::cout << m_data[i] << "\t";

		if ( (i + 1) % m_size_n == 0) {
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;
}

template <typename T>
void Array2D<T>::fill(T value)
{
	for (unsigned int i = 0; i < m_size_m * m_size_n; i++) {
		m_data[i] = value;
	}
}


#endif