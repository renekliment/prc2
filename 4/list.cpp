#include "list.h"
#include <iostream>

using std::swap;
using std::cout;

List::List()
: m_head(new ListItem), m_tail(m_head)
{

}

List::List(const List &list)
: m_head(new ListItem), m_tail(m_head)
{
	for (ListItem *p = list.m_head; p != list.m_tail; p = p->next) {
		insertE(p->data);
	}
}

List::~List()
{
	flush();
	delete m_tail;
}

List &List::operator=(List list)
{
	swap(m_head, list.m_head);
	swap(m_tail, list.m_tail);

	return *this;
}

void List::print() const
{

	for (ListItem *p = m_head; p != m_tail; p = p->next) {
		cout << p->data << " ";
	}

}

void List::insertB(T data)
{

}

void List::insertE(T data)
{
	ListItem *newItem;
	newItem = new ListItem;
	newItem->data = data;
	newItem->next = m_tail;

	ListItem *p;
	for (p = m_head; p->next != m_tail; p = p->next) {

	}

	p->next = newItem;


}

void List::flush()
{

	ListItem *current = m_head;
	ListItem *next;

	if (!isEmpty()) {

		do {

			next = current->next;
			delete current;
			current = next;

		} while (current != m_tail);

	}

}