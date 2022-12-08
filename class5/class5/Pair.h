#pragma once

#include <string>
#include <iostream>
#include "Object5.h"
using namespace std;

class Pair : public Object
{
protected:
	int first;
	int second;
public:
	Pair(void);
	Pair(int, int);
	Pair(const Pair&);

	virtual ~Pair();
	void Show();

	int GetFirst();
	int GetSecond();

	void SetFirst(int);
	void SetSecond(int);

	Pair& operator=(const Pair&);
	bool operator==(const Pair&);

	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
};
