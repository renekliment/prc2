#ifndef SEZNAM_H_INCLUDED
#define SEZNAM_H_INCLUDED

#include <ostream>


typedef int T;

class Seznam
{
	friend std::ostream &operator<<(std::ostream &proud, const Seznam &seznam);
	
public:
	Seznam();
	Seznam(const Seznam &seznam);
	~Seznam();

	Seznam &operator=(Seznam pravaStrana);

	bool jePrazdny() const;
	void vlozNaZacatek(T data);
	void vlozNaKonec(T data);
	void vyprazdni();

	Iterator begin();
	Iterator end();	
	
	class Iterator {
		
		friend class Seznam;
		
	public:
		Iterator &operator++(); // ++z
		const Iterator operator++(int); // z++
		
		T &operator*() const { return m_p->data; }
		T *operator->() const { return &(operator*()); };
		
		bool operator==(Iterator hu) const { return (iter.m_prvek == m_prvek); }
		bool operator!=(Iterator hu) const { return (iter.m_prvek != m_prvek); }
		
	private:
		Prvek *m_p;
	};
	
private:
	struct Prvek
	{
		T data;
		Prvek *dalsi;
	};

	Prvek *m_hlava, *m_zarazka;
	
};


#endif
