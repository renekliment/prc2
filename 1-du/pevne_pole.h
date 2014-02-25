#ifndef PEVNE_POLE_H_INCLUDED
#define PEVNE_POLE_H_INCLUDED


const unsigned int N = 3;

// Deklarace tridy PevnePole - pole N cisel typu double alokovane staticky
class PevnePole
{
// Verejne dostupne slozky tridy
public:
	PevnePole(); // Konstruktor

	unsigned int velikost() const { return N; }

	void nastavPrvek(unsigned int index, double hodnota);
	double zjistiPrvek(unsigned int index) const;

	void vypis() const;

// Slozky tridy dostupne pouze zevnitr tridy
private:
	double m_data[N];
};


#endif
