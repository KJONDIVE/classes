#pragma once

#include "Object5.h"
#include <string>
#include <iostream>

using namespace std;

class Vector
{
private:
	Object** beginning;//��������� �� ������ ������� �������
	int size;//������
	int current;//������� �������
public:
	Vector(void);//����������� ��� ����������
	Vector(int);//����������� �����������
	~Vector(void);//����������
	void Add(Object*);//���������� �������� � ������
	friend ostream& operator<<(ostream& out, const Vector&);//�������� ������
};
