// класс Полином - упорядоченный односвязный список Мономов
// поддерживает операции Печать, Вставка монома, Удаление монома,  
// Поиск монома, Сложение полиномов(слияние упорядоченных списков), 
// Умножение полиномов

#ifndef __polinom_h_
#define __polinom_h_

#include "monom.h"
#include "list.h"

class polinom : public list<monom>
{
public:
	polinom           ()                  : list<monom>() {};
	polinom           (const polinom &pl) : list<monom>(pl) {};
	~polinom          () {};
	void     simplify ();
	void     add      (double _c, int _p);
	polinom& operator=(const polinom &pl);
	polinom  operator*(const double   d );
	polinom  operator*(const polinom &pl);
	polinom  operator+(const polinom &pl);
	polinom  operator-(const polinom &pl);
};

#endif