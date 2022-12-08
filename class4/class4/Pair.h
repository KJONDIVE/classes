#pragma once

#include <string>
#include <iostream>
using namespace std;

class Pair
{
protected:
	int first;
	int second;
public:
	Pair(void);
	Pair(int, int);
	Pair(const Pair&);

	virtual ~Pair();

	int GetFirst();
	int GetSecond();

	void SetFirst(int);
	void SetSecond(int);

	Pair& operator=(const Pair&);
	bool operator==(const Pair&);

	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
};
