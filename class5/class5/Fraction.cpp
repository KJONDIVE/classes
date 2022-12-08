#include "Fraction.h"

Fraction::Fraction(void) : Pair()
{
	SetInt(0);
	SetFrac(0);
}

Fraction::~Fraction(void)
{

}

Fraction::Fraction(int f, int s) : Pair(f, s)
{
	if (s != 0) {
		SetInt(f / s);
		SetFrac(f % s);
	}
	else {
		SetInt(0);
		SetFrac(0);
	}
}

Fraction::Fraction(const Fraction& S)
{
	this->first = S.first;
	this->second = S.second;
	this->intPart = S.intPart;
	this->fracPart = S.fracPart;
}

void Fraction::SetInt(int F)
{
	intPart = F;
}
void Fraction::SetFrac(int S)
{
	fracPart = S;
}

int Fraction::GetInt()
{
	return intPart;
}

int Fraction::GetFrac()
{
	return fracPart;
}


Fraction& Fraction::operator=(const Fraction& s)
{
	if (&s == this)
		return *this;
	first = s.first;
	second = s.second;
	intPart = s.intPart;
	fracPart = s.fracPart;
	return *this;
}

bool Fraction::operator==(const Fraction& s)
{
	return (first == s.first && s.second == second);
}

bool Fraction::operator>(const Fraction& s)
{
	if (second != 0 and s.second != 0 and first / second > s.first / s.second) {
		return true;
	}
	else if (s.second == 0 and first / second > 0) {
		return true;
	}
	return false;
}

istream& operator>>(istream& in, Fraction& s)
{
	int f, sec;
	cout << "First: "; in >> f;
	cout << "Second: "; in >> sec;
	if (sec != 0) {
		s.SetFirst(f);
		s.SetSecond(sec);
		s.SetInt(f / sec);
		s.SetFrac(f % sec);
	}
	else {
		s.SetInt(0);
		s.SetFrac(0);
	}
	
	return in;
}

ostream& operator<<(ostream& out, const Fraction& s)
{
	out << "\nFirst: " << s.first;
	out << "\nSecond: " << s.second;
	out << "\nIntPart: " << s.intPart;
	out << "\nFracPart: " << s.fracPart;
	return out;
}

void Fraction::Show()
{
	cout << "\n[Show]: ";
	cout << "\nFirst: " << first;
	cout << "\nSecond: " <<second;
	cout << "\nIntPart: " << intPart;
	cout << "\nFracPart: " << fracPart;
	cout << endl;
}
