/* 
 * File:   Primes.cpp
 * Author: renekl
 * 
 * Created on 22. březen 2014, 17:46
 */

#include "Primes.h"

#include "dynamicke_pole.h"
#include <math.h>

Primes::Primes(unsigned int n) : m_limit(n), m_array(n) {
    // copyright: http://www.algoritmy.net/article/65/Eratosthenovo-sito   
        for (unsigned int i=0; i < n; i++) {
            m_array[i] = true;
        }

        // nula a jedna nejsou prvocisla
        if (0 < n) m_array[0] = false;
        if (1 < n) m_array[1] = false;       
        
        for (unsigned int i=2; i <= sqrt((double)n); i++) {
            if (m_array[i] == false) continue;
            
            for (unsigned int j = 2*i; j < n; j += i) { // samotne citani
                m_array[j] = false; // nemuze byt z definice prvocislem (je nasobkem jineho cisla)
            }
        }
    
}

//Primes::Primes(const Primes& orig) {
//}

bool Primes::isPrime(unsigned int n) const {
    
    if (n < m_limit) return m_array[n];
    
    /* can't do exceptions in C++ yet and it's useless to bother with assert() really,
     * since its usage is clear
     */

    return false; 
}


