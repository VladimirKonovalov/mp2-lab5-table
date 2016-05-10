#pragma once
#ifndef _sort_h_
#define _sort_h_
#include "keypolnode.h"
#include <iostream>

#define DEFAULT_TABLE_SIZE 256

class sorttable {
public:
	keypol* table;
	int size;
	int n_empty;
	sorttable(int _size = 0);
	~sorttable();
	void insert(string _key, Tp _data);
	int search(string _key);
	void del(string _key);
	void writetab();
};

#endif