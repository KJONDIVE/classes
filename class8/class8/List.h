#pragma once
#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Event.h"
#include <iostream>
using namespace std;

class Vector
{
public:
	Vector(int);//конструктор с параметрами


public:
	~Vector(void);//деструктор
	void Add();//добавление элемента в вектор
	void Del();
	void Show();
	void Show(int);
	int operator()();//размер вектора
	Object* operator[](int);//размер вектора
protected:
	Object** beg;//указатель на первый элемент вектора
	int size;//размер
	int cur;//текущая позиция
};