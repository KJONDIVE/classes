#pragma once
#include "Person5.h"
class Student : public Person
{
protected:
	int mark;
	string pred;
public:
	Student(void);
	~Student(void);
	void Show();//функция для просмотра атрибутов класса 
	Student(string, int, string, int);
	Student(const Student&);

	string GetPred();
	int GetMark();

	void SetPred(string);
	void SetMark(int);

	Student& operator=(const Student&);
	friend istream& operator>>(istream& in, Student& s);
	friend ostream& operator<<(ostream& out, const Student& s);

	void GetQuality();
};
