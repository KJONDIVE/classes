#include "Time.h"
#include <set>	
#include <iostream>
#include <algorithm>
using namespace std;


Time s;
Time replace_value(0, 0);


struct Equal_s
{
	bool operator()(Time t)
	{
		return t == s;
	}
};

struct CmpTime
{
	bool operator()(const Time& a, const Time& b) const
	{
		return a < b;
	}
};

typedef set<Time, CmpTime> st;


//формирование
st make(int n)
{
	Time a;
	st v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.insert(a);
	}
	return v;
}
//печать
void print(st v)
{
	auto i = v.begin();
	while (i != v.end()) {
		std::cout << *i << endl;
		++i;
	}
	std::cout << endl;
}

Time average(st::iterator b, st::iterator e)
{
	Time s = Time(0, 0);
	int n = 0;
	auto i = b;
	//перебор вектора
	while (i != e) {
		s = s + *i;
		n++;
		++i;
	}
	return s / n;
}

void sum_s(Time& t)
{
	t = t + s;
}

void main()
{
	int n;
	cout << "N? ";
	cin >> n;
	st v;
	v = make(n);
	cout << "set: " << endl;
	print(v);

	// replace max elements
	s = *max_element(v.begin(), v.end());
	cout << "max = " << s << endl;
	replace_if(v.begin(), v.end(), Equal_s(), replace_value);
	cout << "replacing max with " << replace_value << endl;
	cout << "set: " << endl;
	print(v);

	// delete min elements
	s = *min_element(v.begin(), v.end());
	cout << "min = " << s << endl;
	auto i = remove_if(v.begin(), v.end(), Equal_s());
	//удалили элементы, начиная с i и до конца вектора
	v.erase(i, v.end());
	cout << "removing min element" << endl;
	cout << "set: " << endl;
	print(v);

	 //sum average
	s = average(v.begin(), v.end());
	cout << "avg = " << s << endl;
	for_each(v.begin(), v.end(), sum_s);
	cout << "sum average for each element" << endl;
	cout << "set: " << endl;
	print(v);
}