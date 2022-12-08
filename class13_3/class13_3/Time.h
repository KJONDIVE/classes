#pragma once

#include <iostream>
using namespace std;

class Time
{
public:
	Time(void);
	Time(int, int);
	Time(const Time&);
	int getMin()
	{
		return min;
	}
	int getSec()
	{
		return sec;
	}
	void setMin(int M)
	{
		this->min = M;
	}
	void setSec(int S)
	{
		this->min += S / 60;
		this->sec = S % 60;
	}
	//������������� �������� �����-������
	Time& operator = (const Time& t) ;
	friend bool operator<(const Time& t1, const Time& t2);
	//bool operator > (const Time& t) const;
	//bool operator < (const Time& t) const;
	bool operator == (const Time& t);
	Time operator + (const Time& t);
	Time operator + (const int k);
	Time operator / (const int k);
	friend ostream& operator<< (ostream& out, const Time&);
	friend istream& operator>> (istream& in, Time&);

private:
	int min, sec;
};

