#pragma once
#ifndef _hash_h_
#define _hash_h_
#include "keypolnode.h"


#define DEFAULT_TABLE_SIZE 256

class hashtable {
public:
	keypolnode* table;
	int size;
	hashtable();
	hashtable(int _size);
	~hashtable();
	int hash(string _key);
	void insert(keypolnode* _keypolnode);
	void insert(string _key, Tp _data);
	keypolnode* search(string _key);
	void del(string _key);
	void writetab();
};

#endif