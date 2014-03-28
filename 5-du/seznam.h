#ifndef SEZNAM_H_INCLUDED
#define SEZNAM_H_INCLUDED

#include <ostream>


typedef int T;

class Seznam
{
    public:
	Seznam();
	Seznam(const Seznam &seznam);
	~Seznam();

	Seznam &operator=(Seznam pravaStrana);

	bool jePrazdny() const;
	void vlozNaZacatek(T data);
	void vlozNaKonec(T data);
	void vyprazdni();

    private:
	struct Prvek
	{
		T data;
		Prvek *dalsi;
	};

	Prvek *m_hlava, *m_zarazka;

    // Iteratory
    public:
        
	class Iterator // Obycejny iterator - umoznuje menit data ulozena v seznamu
	{
            friend class Seznam;

            public:
                T &operator*() const  { return m_prvek->data; }
                T *operator->() const { return &(operator*()); }

                Iterator &operator++();
                const Iterator operator++(int);

                bool operator==(Iterator iter) const { return (m_prvek == iter.m_prvek); }
                bool operator!=(Iterator iter) const { return !(*this == iter); }

            private:
                Prvek *m_prvek;
	};

	class KonstantniIterator // Konstantni iterator - neumoznuje menit seznam
	{
            friend class Seznam;

            public:
                const T &operator*() const  { return m_prvek->data; }
                const T *operator->() const { return &(operator*()); }

                KonstantniIterator &operator++();
                const KonstantniIterator operator++(int);

                bool operator==(KonstantniIterator iter) const { return (m_prvek == iter.m_prvek); }
                bool operator!=(KonstantniIterator iter) const { return !(*this == iter); }

            private:
                const Prvek *m_prvek;
	};

	Iterator begin();
	Iterator end();
	KonstantniIterator begin() const;
	KonstantniIterator end() const;
        
        void vlozZa(Iterator iter, T data);
        void odstran(Iterator iter);
};


std::ostream &operator<<(std::ostream &proud, const Seznam &seznam);


#endif
