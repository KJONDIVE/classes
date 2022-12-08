#include <iostream>
using namespace std;

class Time
{
	int min;
	int sec;

public:
	Time()
	{
		setMin(0);
		setSec(0);
		cout << "����������� ��� ���������� ��� ������� " << this << " ������." << endl;
	}
	Time(int F, int S)
	{
		setMin(F);
		setSec(S);
		cout << "����������� � ����������� ��� ������� " << this << " ������." << endl;
	}
	Time(const Time& t)
	{
		setMin(t.min);
		setSec(t.sec);
		cout << "����������� ����������� ��� ������� " << this << " ������." << endl;
	}
	~Time()
	{
		cout << "���������� ��� ������� " << this << " ������." << endl;
	}
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
		min = M;
	}
	void setSec(int S)
	{
		min += S / 60;
		sec = S % 60;
	}

	//������. ��������
	Time& operator = (const Time& t);
	Time operator + (const Time& t);
	bool operator == (const Time& t);

	//���������� �������
	friend istream& operator >> (istream& in, Time& t);
	friend ostream& operator << (ostream& out, const Time& t);
};
