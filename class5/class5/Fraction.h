#pragma once

#include <string>
#include "Pair.h"

class Fraction : public Pair
{
protected:
	int intPart;
	int fracPart;
public:
	Fraction(void);
	Fraction(int, int);
	Fraction(const Fraction&);

	~Fraction(void);
	void Show();

	int GetInt();
	int GetFrac();

	void SetInt(int);
	void SetFrac(int);

	Fraction& operator=(const Fraction&);
	bool operator==(const Fraction&);
	bool operator>(const Fraction&);
	//bool operator<(const Fraction&);

	friend istream& operator>>(istream& in, Fraction& s);
	friend ostream& operator<<(ostream& out, const Fraction& s);
};
