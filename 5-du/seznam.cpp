#include <algorithm>
#include "seznam.h"

using namespace std;


Seznam::Seznam()
: m_hlava(new Prvek), m_zarazka(m_hlava)
{
}

Seznam::Seznam(const Seznam &seznam)
: m_hlava(new Prvek), m_zarazka(m_hlava)
{
	for (Prvek *p = seznam.m_hlava; p != seznam.m_zarazka; p = p->dalsi)
		vlozNaKonec(p->data);
}

Seznam::~Seznam()
{
	vyprazdni();
	delete m_zarazka;
}

Seznam &Seznam::operator=(Seznam pravaStrana)
{
	swap(m_hlava, pravaStrana.m_hlava);
	swap(m_zarazka, pravaStrana.m_zarazka);

	return *this;
}

bool Seznam::jePrazdny() const
{
	return (m_hlava == m_zarazka);
}

void Seznam::vlozNaZacatek(T data)
{
	Prvek *novy = new Prvek;
	novy->data = data;
	novy->dalsi = m_hlava;
	m_hlava = novy;
}

void Seznam::vlozNaKonec(T data)
{
	Prvek *novaZarazka = new Prvek;
	m_zarazka->data = data;
	m_zarazka->dalsi = novaZarazka;
	m_zarazka = novaZarazka;
}

void Seznam::vyprazdni()
{
	while (!jePrazdny())
	{
		Prvek *p = m_hlava;
		m_hlava = m_hlava->dalsi;
		delete p;
	}
}

Seznam::Iterator Seznam::begin()
{
	Iterator iter;
	iter.m_prvek = m_hlava;
	return iter;
}

Seznam::Iterator Seznam::end()
{
	Iterator iter;
	iter.m_prvek = m_zarazka;
	return iter;
}

Seznam::KonstantniIterator Seznam::begin() const
{
	KonstantniIterator iter;
	iter.m_prvek = m_hlava;
	return iter;
}

Seznam::KonstantniIterator Seznam::end() const
{
	KonstantniIterator iter;
	iter.m_prvek = m_zarazka;
	return iter;
}

void Seznam::vlozZa(Seznam::Iterator iter, T data)
{
    Prvek *novy = new Prvek;
    novy->data = data;
    novy->dalsi = iter.m_prvek->dalsi;
    iter.m_prvek->dalsi = novy;
}

void Seznam::odstran(Seznam::Iterator iter)
{
    Prvek *toDelete;
    Prvek *current = m_hlava;
    while (current->dalsi != iter.m_prvek) {
        current = current->dalsi;
    }
    toDelete = current->dalsi;
  
    current->dalsi = current->dalsi->dalsi;
    
    iter.m_prvek = current;
    
    delete toDelete;
}

// Trida Iterator
Seznam::Iterator &Seznam::Iterator::operator++()
{
	m_prvek = m_prvek->dalsi;
	return *this;
}

const Seznam::Iterator Seznam::Iterator::operator++(int)
{
	Iterator iter(*this);
	++(*this);
	return iter;
}

// Trida KonstantniIterator
Seznam::KonstantniIterator &Seznam::KonstantniIterator::operator++()
{
	m_prvek = m_prvek->dalsi;
	return *this;
}

const Seznam::KonstantniIterator Seznam::KonstantniIterator::operator++(int)
{
	KonstantniIterator iter(*this);
	++(*this);
	return iter;
}


ostream &operator<<(ostream &proud, const Seznam &seznam)
{
	for (Seznam::KonstantniIterator iter = seznam.begin(); iter != seznam.end(); ++iter)
		proud << *iter << " ";

	return proud;
}
