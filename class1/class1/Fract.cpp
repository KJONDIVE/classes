#include <iostream> 
#include <math.h>
#include "Fract.h"
using namespace std;

void Fract::Init(int First, int Second) // инициализациz полей 
{
	first = First;
	second = Second;
}
void Fract::Read() // чтение значений полей 
{
	setlocale(LC_ALL, "rus");
	cout << "First: "; cin >> first;
	cout << "Second: "; cin >> second;
	cout << endl;
}

int Fract::ipart() // целая часть
{
	if (second != 0) {
		return first / second;
	}
	else {
		return 0;
	}
}

void Fract::Show() // вывод значений полей 
{
	cout << "First = " << first << endl;
	cout << "Second = " << second << endl;
}

