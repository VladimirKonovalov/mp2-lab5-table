#include "hash.h"
#include <iostream>

using namespace std;

void main(void) {
	int size;
	Tp _data;
	string _key;
	cout << "enter size: ";
	cin >> size;
	hashtable tab(size);

	for (int i = 0; i < size; i++) {
		cout << "key[" << i << "] ";
		cin >> _key;
		cout << "data[" << i << "] ";
		cin >> _data;
		tab.insert(_key, _data);
	}
	
	cout << "search: ";
	cin >> _key;
	cout << tab.search(_key)->getdata() << endl;

	cout << endl;
	cout << "Hashtable:" << endl;
	tab.writetab();
	cout << endl;
}