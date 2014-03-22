/* 
 * File:   Primes.h
 * Author: renekl
 *
 * Created on 22. březen 2014, 17:46
 */

#ifndef PRIMES_H
#define	PRIMES_H

#include "dynamicke_pole.h"

class Primes {
public:
    Primes(unsigned int n);
    bool isPrime(unsigned int n) const;
private:
    unsigned int m_limit;
    DynamickePole m_array;
};

#endif	/* PRIMES_H */

