#include "polinom.h"

void polinom::simplify()
{
	node<monom>* curr = new node<monom>();
	node<monom>* prev = new node<monom>();
	curr = head;
	prev = NULL;
	while ((prev == NULL)&&(curr != curr->getnext()))
	{
		if (curr->getdata().getcoef() == 0)
		{
			curr = curr->getnext();
			delfirst();
		}
		else 
		{
			prev = curr;
			curr = prev->getnext();
		}
	}
	while (curr != curr->getnext())
	{
		if (curr->getdata().getcoef() == 0)
		{
			curr = curr->getnext();
			delnext(prev);
		}
		else
		{
			prev = curr;
			curr = prev->getnext();
		}
	}
}

void polinom::add(double _c, int _p)
{
	if (_c == 0) return;
	node<monom> *newm  = new node<monom>(monom(_c,_p));
	if (newm->getdata() > head->getdata())
	{
		node<monom> *temp = head;
		head = newm;
		newm->setnext(temp);
	}
	else
	{
		if (newm->getdata() == head->getdata())
		{
			if (head->getnext() != head)
				head->setdata(newm->getdata() + head->getdata());
			else
			{
				newm->setnext(head);
				head = newm;
			}
		}
		else
		{
			node<monom>* curr = head->getnext();
			node<monom>* prev = head;
			while ((newm->getdata() <= curr->getdata())&&(curr->getnext() != curr))
			{
				prev = curr;
				curr = curr->getnext();
			}

			if (newm->getdata() == prev->getdata())
			{
				if (prev->getnext() != prev)
					prev->setdata(newm->getdata()+prev->getdata());
				else
				{
					prev->setnext(newm); 
					newm->setnext(curr);
				}
			}
			else
				if (newm->getdata() >= curr->getdata())
				{
					prev->setnext(newm);
					newm->setnext(curr);
				}
		}
	}
}

polinom& polinom::operator=(const polinom &pl)
{
	if (this == &pl) return *this;
	
	if (head != head->getnext()) dellist();
	
	head = new node<monom>;
	head->setnext(head);
	
	node<monom> *curr;
	curr = pl.gethead();
	while (curr != curr->getnext())
	{
		add(curr->getdata().getcoef(), curr->getdata().getpow());
		curr = curr->getnext();
	}
	return *this;
}

polinom  polinom::operator*(const double   d )
{
	polinom res;
	node<monom> *curr = new node<monom>;
	curr = gethead();
	while (curr != curr->getnext())
	{
		res.add(d * curr->getdata().getcoef(), curr->getdata().getpow());
		curr = curr->getnext();
	}
	res.simplify();
	return res;
}

polinom  polinom::operator*(const polinom &pl)
{
	polinom res;
	node<monom> *left = new node<monom>;
	node<monom> *right = new node<monom>;
	left = gethead();

	while (left != left->getnext())
	{
		right = pl.gethead();
		while (right != right->getnext())
		{
			int _pow = left->getdata().getpow() + right->getdata().getpow();
			int A = _pow % 10; _pow = _pow / 10;
			int B = _pow % 10; int C = _pow /10;
			if ((A<0)||(A>9)||(B<0)||(B>9)||(C<0)||(C>9))
				throw ("illigal pow");
			res.add(left->getdata().getcoef() * right->getdata().getcoef(), left->getdata().getpow() + right->getdata().getpow());
			right = right->getnext();
		}
		left = left->getnext();
	}
	res.simplify();
	return res;
}

polinom  polinom::operator+(const polinom &pl)
{
	polinom res;
	node<monom> *left = new node<monom>;
	node<monom> *right = new node<monom>;
	left = gethead();
	right = pl.gethead();
	
	if (right->getdata().getcoef() == 0) return *this;
	if (left->getdata().getcoef() == 0) return pl;

	while ((right != right->getnext()) || (left != left->getnext()))
	{
		if (left->getdata() == right->getdata())
		{
			res.add(left->getdata().getcoef() + right->getdata().getcoef(), left->getdata().getpow());
			left = left->getnext();
			right = right->getnext();
		}
		else
			if (left->getdata() > right->getdata())
			{
				res.add(left->getdata().getcoef(), left->getdata().getcoef());
				left = left->getnext();
			}
			else
				if (left->getdata() < right->getdata())
				{
					res.add(right->getdata().getcoef(), right->getdata().getpow());
					right = right->getnext();
				}
	} 

	if (gethead() == gethead()->getnext())
		res.add(gethead()->getdata().getcoef(), gethead()->getdata().getpow());
	if (pl.gethead() == pl.gethead()->getnext())
		res.add(pl.gethead()->getdata().getcoef(), pl.gethead()->getdata().getpow());

//	res.simplify();
	return res;
}

polinom  polinom::operator-(const polinom &pl)
{
	polinom res;

	node<monom> *left = new node<monom>;
	node<monom> *right = new node<monom>;
	left = gethead();
	right = pl.gethead();

	while ((right != right->getnext())||(left != left->getnext()))
	{
		if (left->getdata() == right->getdata())
		{
			res.add(left->getdata().getcoef() - right->getdata().getcoef(), left->getdata().getpow());
			left = left->getnext();
			right = right->getnext();
		}
		else
			if (left->getdata() > right->getdata())
			{
				res.add(left->getdata().getcoef(), left->getdata().getcoef());
				left = left->getnext();
			}
			else
				if (left->getdata() < right->getdata())
				{
					res.add(right->getdata().getcoef(), right->getdata().getpow());
					right = right->getnext();
				}
	}
	if (left == left->getnext())
	while (right != right->getnext())
	{
		res.add(-right->getdata().getcoef(), right->getdata().getpow());
		right = right->getnext();
	}
	else
		while (left != left->getnext())
		{
			res.add(left->getdata().getcoef(), left->getdata().getpow());
			left = left->getnext();
		}
	//res.simplify();
	return res;
}