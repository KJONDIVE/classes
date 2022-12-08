#include "Pair.h"

Pair::Pair(void)
{
	SetFirst(0);
	SetSecond(0);
}

Pair::~Pair(void)
{
	cout << "Деструктор вызван" << this;
}

Pair::Pair(int f, int s)
{
	SetFirst(f);
	SetSecond(s);
}

Pair::Pair(const Pair& p)
{
	SetFirst(p.first);
	SetSecond(p.second);
}

void Pair::SetFirst(int f)
{
	first = f;
}

void Pair::SetSecond(int s)
{
	second = s;
}

int Pair::GetSecond()
{
	return second;
}

int Pair::GetFirst()
{
	return first;
}

Pair& Pair::operator=(const Pair& p)
{
	if (&p == this)
		return *this;
	SetFirst(p.first);
	SetSecond(p.second);
	return *this;
}

bool Pair::operator==(const Pair& p)
{
	return (this->first > p.first) || (this->first == p.first && this->second > p.second);
}

istream& operator>>(istream& in, Pair& p)
{
	int f, s;
	cout << "First: "; in >> f;
	cout << "Second: "; in >> s;
	p.SetFirst(f);
	p.SetSecond(s);
	return in;
}

ostream& operator<<(ostream& out,const Pair& p)
{
	out << "First: " << p.first << endl;
	out << "Second: " << p.second << endl;
	return out;
}
