#include "monom.h"

monom& monom::operator=(const monom &m)
{
	if (this == &m) return *this;

	coef = m.coef;
	pow = m.pow;
	
	return *this;
}
monom monom::operator+(const monom &m)
{
	monom res;
	if (pow != m.pow) throw("illigal operator");
	res.coef = coef + m.coef;
	res.pow = pow;
	return res;
}
monom monom::operator-(const monom &m)
{
	monom res;
	if (pow != m.pow) throw("illigal operator");
	res.coef = coef - m.coef;
	res.pow = pow;
	return res;
}
monom monom::operator*(const monom &m)
{
	monom res;
	res.coef = coef * m.coef;
	res.pow = pow + m.pow;
	return res;
}
monom monom::operator*(const double d)
{
	monom res;
	res.coef = coef * d;
	res.pow = pow;
	return res;
}