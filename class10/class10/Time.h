#pragma once

#include <fstream> //библиотека для работы со файловыми потоками
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
	//перегруженные операции ввода-вывода
	Time& operator = (const Time& t);
	bool operator == (const Time& t);
	Time operator + (const Time& t);
	Time operator + (const int k);
	friend ostream& operator<< (ostream& out, const Time&);
	friend istream& operator>> (istream& in, Time&);

	friend fstream& operator>>(fstream& fin, Time& p);
	friend fstream& operator <<(fstream& fout, const Time& p);

private:
	int min, sec;
};

