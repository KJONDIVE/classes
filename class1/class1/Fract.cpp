#include <iostream> 
#include <math.h>
#include "Fract.h"
using namespace std;

void Fract::Init(int First, int Second) // ������������z ����� 
{
	first = First;
	second = Second;
}
void Fract::Read() // ������ �������� ����� 
{
	setlocale(LC_ALL, "rus");
	cout << "First: "; cin >> first;
	cout << "Second: "; cin >> second;
	cout << endl;
}

int Fract::ipart() // ����� �����
{
	if (second != 0) {
		return first / second;
	}
	else {
		return 0;
	}
}

void Fract::Show() // ����� �������� ����� 
{
	cout << "First = " << first << endl;
	cout << "Second = " << second << endl;
}

