#include <iostream>
#include "array2D.h"

using namespace std;

int main()
{
	Array2D a(1, 1);
	Array2D b(10, 8);
	Array2D c(1, 48654);

	a.set(0, 0, 56);

	b.set(0, 0, 15);
	b.set(1, 1, 16);
	b.set(1, 0, 3.14159);

	cout << "pi = " << b.get(1, 0) << endl;

	a.print();
	b.print();
	//c.print();

	b.fill(2.7);
	b.print();

	b.set(3, 3, 3.14);

	Array2D clone(b);
	clone.print();

	return 0;
}
