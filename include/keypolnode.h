#pragma once
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

typedef int Tp;

struct keypol {
	string k; //key
	Tp d;	  //data
};

class keypolnode {
protected:
	keypol data;
	keypolnode* next;
public:
	keypolnode();
	keypolnode(string _key);
	keypolnode(string _key, Tp _data);
	~keypolnode();
	void setdata(Tp _data);
	Tp getdata();
	void setkey(string _key);
	string getkey();
	void setnext(keypolnode* _next);
	keypolnode* getnext();
};
