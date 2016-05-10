#ifndef __monom_h_
#define __monom_h_

#include <iostream>

using namespace std;

class monom
{
protected:
	double coef;
	int    pow;
public:
	monom            (){coef = 0; pow = 0;};
	monom            (double _d) {coef = _d; pow = 0;}; 
	monom            (double _c, int _p){coef = _c; pow = _p;};
	monom            (const monom &m){coef = m.coef; pow = m.pow;};
	~monom           ()              {};
	double getcoef   ()              {return coef;};
	int	   getpow    ()              {return pow;};
	monom& operator= (const monom &m);
	monom  operator+ (const monom &m);
	monom  operator- (const monom &m);
	monom  operator* (const monom &m);
	monom  operator* (const double d);
	bool   operator> (const monom &m)
	{
		if (pow > m.pow) return 1;
		else return 0;
	}
	bool   operator< (const monom &m)
	{
		if (pow < m.pow) return 1;
		else return 0;
	}
	bool   operator==(const monom &m)
	{
		if (pow == m.pow) return 1;
		else return 0;
	}
	bool   operator!=(const monom &m)
	{
		return !((pow == m.pow)&&(coef == m.coef));
	}
	bool   operator>=(const monom &m)
	{
		return !(pow < m.pow);
	}
	bool   operator<=(const monom &m)
	{
		return !(pow > m.pow);
	}
	friend istream& operator>>(istream &in, monom &m) 
	{
			in >> m.coef >> m.pow;
		return in;
	}
	friend ostream& operator<<(ostream &out, monom &m) 
	{
			out << m.getcoef() << ' ' << m.getpow();
		return out;
	}
};

#endif