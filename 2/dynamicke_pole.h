#ifndef DYNAMICKE_POLE_H_INCLUDED
#define DYNAMICKE_POLE_H_INCLUDED

class DynamickePole
{
public:
	explicit DynamickePole(unsigned int size);
	DynamickePole(const DynamickePole &array);
	~DynamickePole();

	DynamickePole &operator=(DynamickePole array);

	unsigned int velikost() const { return m_size; }

	void nastavPrvek(unsigned int index, double hodnota);
	double zjistiPrvek(unsigned int index) const;

	void vypis() const;

private:
	unsigned int m_size;

	double *m_data;
};


#endif
