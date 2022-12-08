#include "Time.h"
#include <iostream>

using namespace std;

//���������� �������� ������������ 
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

//���������� �������� �����
istream& operator >> (istream& in, Time& t)
{
	int m, s;
	cout << "Min: "; in >> m;
	cout << "Sec: "; in >> s;
	t.setMin(m);
	t.setSec(s);
	return in;
}

//���������� �������� ������
ostream& operator << (ostream& out, const Time& t)
{
	return (out << t.min << ":" << t.sec);
}

// ���������� �������� ��������
Time Time::operator + (const Time& t)
{
	Time Sum = Time(this->min + t.min, this->sec + t.sec);
	
	return Sum;
}

bool Time::operator == (const Time& t)
{
	return this->min == t.min && this->sec == t.sec;
}
