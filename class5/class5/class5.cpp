#include "Object5.h"
#include "Pair.h"
#include "Fraction.h"
#include "Vector5.h"
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	Pair a;
	cout << "\nPair A: \n";
	cin >> a;
	cout << a << endl; //вывод с помощью перегруженной операции
	cout << "\nObject* p = &a: \n";
	Object* p = &a;
	p->Show(); //вывод с помощью метода Show() и указателя

	cout << "\nFraction B: \n";
	Fraction b;
	cin >> b;
	cout << b << endl;
	cout << "\nObject* p = &b: \n";
	p = &b;
	p->Show();

	cout << "\nVector (size = 5): \n";
	Vector v(5);//вектор из 5 элементов
	cout << "\nPair C: \n";
	Pair c;//объект класса Pair
	cin >> c;
	cout << "\nFraction D: \n";
	Fraction d;// объект класса Fraction
	cin >> d;
	p = &c;//ставим указатель на объект класса Pair
	v.Add(p);//добавляем объект в вектор
	p = &d;//ставим указатель на объект класса Fraction
	v.Add(p); //добавляем объект в вектор
	cout << "\nAdd C to vector: \n";
	cout << "\nAdd D to vector: \n";
	cout << "\nVector = : \n";
	cout << v;//вывод вектора
}



