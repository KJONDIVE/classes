#include <iostream>
#include <string>
#include <Windows.h>
#include "Student.h"

using namespace std;

Student make_student()
{
	string F, G;
	float A;
	cout << "ФИО: "; 
	getline(cin, F);
	cout << "Группа: ";
	getline(cin, G);
	cout << "Средний балл: ";
	cin >> A;
	Student temp(F, G, A);
	return temp;
}

void print_student(Student& t)
{
	t.Show();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "...Конструктор без парметров... \n";
	Student A;
	A.Show();

	cout << "....Конструктор с параметрами... \n";
	Student B("Папанич Петр Алексеевич", "РИС-25-1б", 4.5);
	B.Show();

	cout << "...Конструктор копирования... \n";
	Student C = B;
	print_student(C);

	cout << "...Селекторы... \n";
	Student D;
	D.Set_FIO("Петров Петр Петрович");
	D.Set_Group("РИС-25-1б");
	D.Set_AvgMark(4.5);
	D.Show();

	cout << "...Инициализация через функцию...\n";
	Student E = make_student();
	E.Show();
}
