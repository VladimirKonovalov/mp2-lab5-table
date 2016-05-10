#include "keypolnode.h"

keypolnode::keypolnode() {
	data.d = Tp();
	data.k = '\0';
	next = NULL;
}

keypolnode::keypolnode(string _key) {
	data.d = Tp();
	data.k = _key;
	next = NULL;
}

keypolnode::keypolnode(string _key, Tp _data) {
	data.d = _data;
	data.k = _key;
	next = NULL;
}

keypolnode::~keypolnode() {

}

void keypolnode::setdata(Tp _data) {
	data.d = _data;
}

Tp keypolnode::getdata() {
	return data.d;
}

void keypolnode::setkey(string _key) {
	data.k = _key;
}

string keypolnode::getkey() {
	return data.k;
}

void keypolnode::setnext(keypolnode* _next) {
	next = _next;
}

keypolnode* keypolnode::getnext() {
	return next;
}

