#include "hash.h"

hashtable::hashtable() {
	size = DEFAULT_TABLE_SIZE;
	table = new keypolnode[size];
	for (int i = 0; i < size; i++)
		table[i].setnext(NULL);
}
hashtable::hashtable(int _size) {
	size = _size;
	table = new keypolnode[size];
	for (int i = 0; i < size; i++)
		table[i].setnext(NULL);
}

hashtable::~hashtable() {
	keypolnode *temp, *tmp;
	for (int i = 0; i < size; i++) {
		temp = table[i].getnext();
		while (temp != NULL) {
			tmp = temp;
			temp = temp->getnext();
			delete tmp;
		}
	}
	delete[] table;
}

int hashtable::hash(string _key) {
	int i, ln, sum = 0;
	ln = _key.length();
	for (i = 0; i < ln; i++) sum += (int)_key[i];
	return sum % size;
}

void hashtable::insert(keypolnode* _keypolnode) {
	int key;
	key = hash(_keypolnode->getkey());

	_keypolnode->setnext(table[key].getnext());
	table[key].setnext(_keypolnode);
}

void hashtable::insert(string _key, Tp _data) {
	keypolnode* _keypolnode = new keypolnode;

	int key;
	_keypolnode->setkey(_key);
	_keypolnode->setdata(_data);
	key = hash(_keypolnode->getkey());

	_keypolnode->setnext(table[key].getnext());
	table[key].setnext(_keypolnode);
}

keypolnode* hashtable::search(string _key) {
	int key = hash(_key);
	keypolnode *temp = table[key].getnext();
	while ((temp->getkey() != _key) && (temp->getnext() != NULL)) {
		temp = temp->getnext();
	}
	if (temp->getkey() == _key)
		return temp;
	else
		return NULL;
}

void hashtable::del(string _key) {
	keypolnode *temp = table[hash(_key)].getnext()->getnext();
	keypolnode *prev = table[hash(_key)].getnext();
	if (prev->getkey() == _key) {
		table[hash(_key)].setnext(temp);
		delete prev;
		return;
	}
	else {
		while ((temp->getkey() != _key) || (temp->getnext() != NULL))
			temp = temp->getnext();

		if (temp->getkey() == _key) {
			prev->setnext(temp->getnext());
			delete temp;
			return;
		}
		else
			return;
	}
}

void hashtable::writetab() {
	int i;
	keypolnode *temp;
	for (i = 0; i < size; i++) {
		temp = table[i].getnext();
		if (temp == NULL) continue;
		cout << "table[" << i << "]: ";
		while (temp != NULL) {
			cout << temp->getdata() << ' ';
			temp = temp->getnext();
		}
		cout << endl;
	}
}