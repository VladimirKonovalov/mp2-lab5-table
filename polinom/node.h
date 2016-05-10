#ifndef __node_h_
#define __node_h_

#include <iostream>

using namespace std;

template <class T>
class node
{
protected:
	T data;
	node<T> *next;
public:
	node() {data = T();};
	node(T _data) {data = _data;};
	void setnext(node<T>* _next)
	{
		next = _next;
	}
	node* getnext()
	{
		return next;
	}
	void setdata(T _data)
	{
		data = _data;
	}
	T getdata() {return data;};
	bool operator>(const node<T> &n)
	{
		if (data > n.data) return 1;
		else return 0;
	}
	bool operator<(const node<T> &n)
	{
		if (data < n.data) return 1;
		else return 0;
	}
	bool operator==(const node<T> &n)
	{
		if (data == n.data) return 1;
		else return 0;
	}
	bool operator>=(const node<T> &n)
	{
		return !(data < n.data);
	}
	bool operator<=(const node<T> &n)
	{
		return !(data > n.data);
	}
	~node<T>()
	{
	}
};

#endif