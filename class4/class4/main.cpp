#include "Pair.h"
#include "Fraction.h"
#include <iostream>

using namespace std;

void f1(Pair& p)
{
	p.SetFirst(5);
	cout << p;
}

Fraction f2()
{
	Fraction f(5, 1);
	return f;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "\nPair A: \n";
	Pair a;
	cin >> a;
	cout << a;

	cout << "\nPair B: \n";
	Pair b(36, 18);
	cout << b;

	a = b;
	cout << "\nPair A: \n";
	cout << a;

	cout << "\nFraction C: \n";
	Fraction c;
	cin >> c;
	cout << c;

	cout << "\nNew Pair C: \n";
	f1(c);

	cout << "\nFraction D: \n";
	Fraction d = f2();
	cout << d;

	system("pause");
}