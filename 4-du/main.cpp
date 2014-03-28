#include <iostream>

#include "Primes.h"

using namespace std;

int main(void)
{
    unsigned int n;
    cout << "Enter limit: ";
    cin >> n;
    
    Primes p(n);
    
    unsigned int a;
    
    // enter 0 to exit the program  
    while (true) {
        cout << "Enter a number to test: ";
        cin >> a;
        if (a == 0) break;
         
        cout << a << (p.isPrime(a) ? " is" : " is NOT") << " a prime number." << endl;
    }
    
    return 0;
}