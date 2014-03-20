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
	Iterator hu;
	hu.m_p = m_hlava;
	
	return hu;
}

Seznam::Iterator Seznam::end()
{
	Iterator hu;
	hu.m_p = m_zarazka;
	
	return hu;
}

ostream &operator<<(ostream &proud, const Seznam &seznam)
{
	for (Seznam::Prvek *p = seznam.m_hlava; p != seznam.m_zarazka; p = p->dalsi)
		proud << p->data << " ";

	return proud;
}

Seznam::Iterator &Seznam::Iterator::operator++() // ++z
{
	m_p = m_p->dalsi;
	
	return *this;
}

const Seznam::Iterator Seznam::Iterator::operator++(int) // z++
{
	Iterator copy(*this);

	++(*this);

	return copy;
}	