#include "Vector5.h"

//конструктор без параметров
Vector::Vector(void)
{
	beginning = 0;
	size = 0;
	current = 0;
}

//деструктор
Vector::~Vector(void)
{
	if (beginning != 0)
		delete[] beginning;
	beginning = 0;
}

//конструктор с параметрами
Vector::Vector(int n)
{
	beginning = new Object * [n];
	current = 0;
	size = n;
}

//добавление объекта, на который указывает указатель p в вектор
void Vector::Add(Object* p)
{
	if (current < size)
	{
		beginning[current] = p;
		current++;
	}
}

//операция вывода
ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) 
		out << "Empty" << endl;
	Object** p = v.beginning;//указатель на указатель типа Object
	for (int i = 0; i < v.current; i++)
	{
		(*p)->Show();//вызов метода Show() (позднее связывание)
		p++;//передвигаем указатель на следующий объект
	}
	return out;
}