#include "Time.h"

Time::Time(void)
{
	setMin(0);
	setSec(0);
}
Time::Time(int M, int S)
{
	setMin(M);
	setSec(S);
}
Time::Time(const Time& t)
{
	setMin(t.min);
	setSec(t.sec);
}

ostream& operator<<(ostream& out, const Time& t)
{

	out << t.min << ":" << t.sec;
	return out;
}
istream& operator>>(istream& in, Time& t)
{
	int m, s;
	cout << "Min: "; in >> m;
	cout << "Sec: "; in >> s;
	t.setMin(m);
	t.setSec(s);
	return in;
}

Time Time::operator + (const Time& t)
{
	Time Sum = Time(this->min + t.min, this->sec + t.sec);

	return Sum;
}

Time Time::operator + (const int k)
{
	Time Sum = Time(this->min, this->sec + k);

	return Sum;
}

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

//Time Time::operator+(int k)
//{
//	Time Sum = Time(this->min, this->sec + k);
//
//	return Sum;
//}
