#include "Person5.h"

Person::Person(void)
{
	name = "";
	age = 0;
}

Person::~Person(void)
{
}

Person::Person(string N, int A)
{
	name = N;
	age = A;
}

Person::Person(const Person& p)
{
	name = p.name;
	age = p.age;
}

void Person::SetAge(int A)
{
	age = A;
}

void Person::SetName(string N)
{
	name = N;
}

Person& Person::operator=(const Person& p)
{
	if (&p == this)
		return *this;
	name = p.name;
	age = p.age;
	return *this;
}

istream& operator>>(istream& in, Person& p)
{
	cout << "\nName: "; in >> p.name;
	cout << "Age: "; in >> p.age;
	return in;
}

ostream& operator<<(ostream& out, const Person& p)
{	
	out << "\n[out]:";
	out << "\nName: " << p.name;
	out << "\nAge: " << p.age;
	return out;
}

void Person::Show()
{
	cout << "\n[Show]: ";
	cout << "\nName : " << name;
	cout << "\nAge : " << age;
	cout << endl;
}