#ifndef __list_h_
#define __list_h_

#include <iostream>
#include "node.h"

using namespace std;

/*---------------------------------------*/
template <class T>
class list
{
protected:
	node<T> *head;
public:
	list();
	list(const list &l);
	~list();
	void writelist();
	void add(T _data);
	void delfirst();
	void delnext(node<T> *prev);
	void dellist();
	node<T>* gethead() const {return head;};
	T getheaddata() {return head->getdata();};
};
/*---------------------------------------*/
template <class T>
list<T>::list() 
{
	head = new node<T>(); 
	head->setnext(head);
}

template <class T>
list<T>::list(const list &l) 
{
	head = new node<T>; 
	head->setnext(head);

	node<T> *curr = new node<T>;
	curr = l.head;
	while (curr->getnext() != curr)
	{
		add(curr->getdata());
		curr = curr->getnext();
	}
}

template <class T>
list<T>::~list()
{
	node<T> *temp = new node<T>;
	while (head->getnext() != head) 
	{
		temp = head->getnext();
		delete head;
		head = temp;
	}
	delete temp;
}

template <class T>
void list<T>::writelist()
{
	node<T> *temp = head;
	while (temp->getnext() != temp)
	{
		cout << temp->getdata() << " + ";
		temp = temp->getnext();
	}
	cout << endl;
}

template <class T>
void list<T>::add(T _data)
{
	node<T> *newn  = new node<T>(_data);
	if (newn->getdata() >= head->getdata())
	{
		node<T> *temp = head;
		head = newn;
		newn->setnext(temp);
	}
	else
	{
		node<T>* curr = new node<T>();
		node<T>* prev = new node<T>();
		prev = head;
		curr = head->getnext();
		while ((newn->getdata() < curr->getdata())&&(curr->getnext() != curr))
		{
			prev = curr;
			curr = curr->getnext();
		}
		prev->setnext(newn);
		newn->setnext(curr);
	}
}

template <class T>
void list<T>::delfirst()
{
	node<T>* temp = new node<T>;
	temp = head;
	head = head->getnext();
	delete temp;
}

template <class T>
void list<T>::delnext(node<T> *prev)
{
	node<T>* temp = new node<T>;
	temp = prev->getnext();
	prev->setnext(temp->getnext());
	delete temp;
}

template <class T>
void list<T>::dellist()
{
	while (head->getnext() != head)
		delfirst();
}

#endif