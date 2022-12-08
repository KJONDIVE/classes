#pragma once

#include "Object5.h"
#include <string>
#include <iostream>

using namespace std;

class Vector
{
private:
	Object** beginning;//указатель на первый элемент вектора
	int size;//размер
	int current;//текущая позиция
public:
	Vector(void);//конструктор без параметров
	Vector(int);//конструктор копирования
	~Vector(void);//деструктор
	void Add(Object*);//добавление элемента в вектор
	friend ostream& operator<<(ostream& out, const Vector&);//операция вывода
};
