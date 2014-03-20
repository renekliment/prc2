#ifndef LIST_H
#define LIST_H

typedef int T;

class List {

public:

	List();
	List(const List &list);
	~List();
	List &operator=(List list);

	void print() const;
	bool isEmpty() const { return (m_head == m_tail); }
	void insertB(T data);
	void insertE(T data);
	void flush();

private:

	struct ListItem {

		T data;
		ListItem *next;

	};

	ListItem *m_head, *m_tail;


};

#endif