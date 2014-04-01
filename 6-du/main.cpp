#include <iostream>
#include "array2D.h"

using namespace std;

int main()
{
	Array2D<double> a(1, 1);
	Array2D<double> b(10, 8);
	Array2D<double> c(1, 48654);

	a(0, 0) = 56.62;

	b(0, 0) = 15;
	b(1, 1) = 16;
	b(1, 0) = 3.14159;

	cout << "pi = " << b(1, 0) << endl;

	a.print();
	b.print();
	//c.print();

	b.fill(2.7);
	b.print();

	b(3, 3) = 3.14159;

	Array2D<double> clone(b);
	clone.print();

	return 0;
}
