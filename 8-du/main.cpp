#include <iostream>
#include "pevne_pole.h"
#include "dynamicke_pole.h"

using namespace std;


template<typename T>
void vypln (AbstraktniPole<T> &pole, T hodnota)
{
	for (unsigned int i=0; i < pole.velikost(); i++) {
		pole[i] = hodnota;
	}	

}

// Funkce pocitajici maximum z prvku pole (pole musi mit alespon jeden prvek)
template<typename T>
T maximum(const AbstraktniPole<T> &pole)
{
	T vysledek = pole[0];
	for (unsigned int i = 1; i < pole.velikost(); i++)
		if (pole[i] > vysledek)
			vysledek = pole[i];

	return vysledek;
}

int main()
{
	PevnePole px;
	px[0] = 0.1;
	px[1] = 4.2;
	px[2] = -4.4;
	cout << "px: " << px << endl;
	cout << "Maximum: " << maximum(px) << endl << endl;

	px.vypln(-63.48);
	cout << "px: " << px << endl;
	
	DynamickePole<double> dx(3);
	dx[0] = 0.1;
	dx[1] = 4.2;
	dx[2] = -4.4;
	cout << "dx: " << dx << endl;
	cout << "Maximum: " << maximum(dx) << endl;

	dx.vypln(-63.48);
	cout << "dx: " << dx << endl;
	
	return 0;
}
