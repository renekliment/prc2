#ifndef ARRAY2D_H_INCLUDED
#define ARRAY2D_H_INCLUDED


class Array2D
{
public:
	explicit Array2D(unsigned int m, unsigned int n); // Konstruktor s parametrem
	Array2D(const Array2D &array);      // Kopirovaci konstruktor
	~Array2D();

	Array2D &operator=(Array2D rhs); // Prirazovaci operator

	unsigned int getSize_m() const { return m_size_m; }
	unsigned int getSize_n() const { return m_size_n; }

	void set(unsigned int m, unsigned int n, double value);
	double get(unsigned int m, unsigned int n) const;

	void print() const;

	void fill(double value);

private:
	unsigned int m_size_m, m_size_n;
	double *m_data;
};


#endif