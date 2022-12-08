#include "Vector5.h"

//����������� ��� ����������
Vector::Vector(void)
{
	beginning = 0;
	size = 0;
	current = 0;
}

//����������
Vector::~Vector(void)
{
	if (beginning != 0)
		delete[] beginning;
	beginning = 0;
}

//����������� � �����������
Vector::Vector(int n)
{
	beginning = new Object * [n];
	current = 0;
	size = n;
}

//���������� �������, �� ������� ��������� ��������� p � ������
void Vector::Add(Object* p)
{
	if (current < size)
	{
		beginning[current] = p;
		current++;
	}
}

//�������� ������
ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) 
		out << "Empty" << endl;
	Object** p = v.beginning;//��������� �� ��������� ���� Object
	for (int i = 0; i < v.current; i++)
	{
		(*p)->Show();//����� ������ Show() (������� ����������)
		p++;//����������� ��������� �� ��������� ������
	}
	return out;
}