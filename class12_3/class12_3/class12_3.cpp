#include "Container.h"
#include "Time.h"
#include <iostream>
using namespace std;

void main()
{
	int n; //количество элементов в контейнере
	cout << "N? "; cin >> n;
	Container <Time> v(n);//создать контенер
	v.Print();//напечатать контейнер

	cout << "insert max" << endl;
	v.AddMax();
	cout << "m = " << endl;
	v.Print();

	cout << "remove min " << endl;
	v.RemoveMin();
	cout << "m = " << endl;
	v.Print();

	cout << "sum avg = " << endl;
	v.SumAvg();
	cout << "m = " << endl;
	v.Print();
}