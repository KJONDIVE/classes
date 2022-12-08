#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

//конструктор без параметров
Student::Student()
{
	FIO = "";
	Group = "";
	AvgMark = 0.0;
	cout << "Конструктор без параметров для объекта " << this << " вызван." << endl;
}

//с параметрами
Student::Student(string FIO, string Group, float AvgMark)
{
	this->FIO = FIO;
	this->Group = Group;
	this->AvgMark = AvgMark;
	cout << "Конструктор с параметрами для объекта " << this << " вызван." << endl;
}

//копирования
Student::Student(const Student& t)
{
	FIO = t.FIO;
	Group = t.Group;
	AvgMark = t.AvgMark;
	cout << "Конструктор копирования для объекта " << this << " вызван." << endl;
}
//деструктор
Student::~Student()
{
	cout << "Деструктор для объекта " << this << " вызван." << endl;
}

//селекторы
string Student::Get_FIO()
{
	return FIO;
}

string Student::Get_Group()
{
	return Group;
}

float Student::Get_AvgMark()
{
	return AvgMark;
}

//модификаторы
void Student::Set_FIO(string FIO)
{
	this->FIO = FIO;
}

void Student::Set_Group(string Group)
{
	this->Group = Group;
}

void Student::Set_AvgMark(float AvgMark)
{
	this->AvgMark = AvgMark;
}

//просмотр полей
void Student::Show()
{
	cout << "ФИО: " << FIO << "\n";
	cout << "Группа: " << Group << "\n";
	cout << "Средний балл: " << AvgMark << "\n\n";
}