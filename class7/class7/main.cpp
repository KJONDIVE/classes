#include "Time.h"
#include "Vector.h"
#include <iostream>
#include <Windows.h>


using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//инициализация, ввод и вывод значений вектора
	Vector<int>A = Vector<int>(5, 0);
	cout << "Введите вектор А[5]:" << endl;
	cin >> A;
	cout << A << endl;
	//инициализация и вывод значений вектора
	cout << "Введите вектор B[10]:" << endl;
	Vector <int>B(10, 1);
	cout << B << endl;
	//операция присваивания
	cout << "B = A." << endl;
	B = A;
	cout << B << endl;
	//доступ по индексу
	cout << "А[2] = ";
	cout << A[2] << endl;
	//получение длины вектора
	cout << "Длина = " << A() << endl;
	//операция сложения с константой
	cout << "B = A + 10:" << endl;
	B = A + 10;
	cout << B << endl;

	cout << "Введите Time t = " << endl;
	Time t;
	cin >> t;
	cout << t;


	int k;
	cout << "\nПрибавить к t число K = " << endl;
	cin >> k;
	Time p;
	p = t + k;
	cout << p;

	cout << "Time t = " << endl;
	cin >> t;
	cout << t;	
	cout << "\nВведите вектор С<Time>[5]:" << endl;
	Vector<Time> C = Vector<Time>(5, t);
	cin >> C;
	cout << C << endl;
	Vector<Time>D(10, t);
	cout << D << endl;
	D = C;
	cout << D << endl;
	cout << C[2] << endl;
	cout << "size =" << C() << endl;
	D = C + t;
	cout << D << endl;
}