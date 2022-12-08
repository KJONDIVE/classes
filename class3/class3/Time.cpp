#include "Time.h"
#include <iostream>

using namespace std;

//перегрузка операции присваивания 
Time& Time::operator= (const Time& t)
{
	if (&t == this)
	{
		return *this;
	}
	setMin(t.min);
	setSec(t.sec);
	return *this;
}

//перегрузка операции ввода
istream& operator >> (istream& in, Time& t)
{
	int m, s;
	cout << "Min: "; in >> m;
	cout << "Sec: "; in >> s;
	t.setMin(m);
	t.setSec(s);
	return in;
}

//перегрузка операции вывода
ostream& operator << (ostream& out, const Time& t)
{
	return (out << t.min << ":" << t.sec);
}

// перегрузка операции разности
Time Time::operator + (const Time& t)
{
	Time Sum = Time(this->min + t.min, this->sec + t.sec);
	
	return Sum;
}

bool Time::operator == (const Time& t)
{
	return this->min == t.min && this->sec == t.sec;
}
