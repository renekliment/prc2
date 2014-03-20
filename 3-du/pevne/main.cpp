#include <iostream>

#include "pole.h"

using namespace std;

int main ()
{
	Pole arr;

	arr[0] = 1.5;
	arr[1] = 10;
	arr[2] = -6.78;
	
	cout << arr;

	cout << arr[1] << endl;
	
	return 0;
}