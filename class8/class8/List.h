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
	Vector(int);//����������� � �����������


public:
	~Vector(void);//����������
	void Add();//���������� �������� � ������
	void Del();
	void Show();
	void Show(int);
	int operator()();//������ �������
	Object* operator[](int);//������ �������
protected:
	Object** beg;//��������� �� ������ ������� �������
	int size;//������
	int cur;//������� �������
};