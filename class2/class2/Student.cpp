#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

//����������� ��� ����������
Student::Student()
{
	FIO = "";
	Group = "";
	AvgMark = 0.0;
	cout << "����������� ��� ���������� ��� ������� " << this << " ������." << endl;
}

//� �����������
Student::Student(string FIO, string Group, float AvgMark)
{
	this->FIO = FIO;
	this->Group = Group;
	this->AvgMark = AvgMark;
	cout << "����������� � ����������� ��� ������� " << this << " ������." << endl;
}

//�����������
Student::Student(const Student& t)
{
	FIO = t.FIO;
	Group = t.Group;
	AvgMark = t.AvgMark;
	cout << "����������� ����������� ��� ������� " << this << " ������." << endl;
}
//����������
Student::~Student()
{
	cout << "���������� ��� ������� " << this << " ������." << endl;
}

//���������
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

//������������
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

//�������� �����
void Student::Show()
{
	cout << "���: " << FIO << "\n";
	cout << "������: " << Group << "\n";
	cout << "������� ����: " << AvgMark << "\n\n";
}