#include "Time.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<Time> vec;
Time s;
Time replace_value(0, 0);

struct Greater_s //больше, чем s
{
	bool operator()(Time t)
	{
		if (t > s) return true; else return false;
	}
};

struct Equal_s
{
	bool operator()(Time t)
	{
		return t == s;
	}
};



//формирование вектора
vec make_vector(int n)
{
	Time a;
	vec v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}
//печать вектора
void print_vector(vec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	cout << endl;
}

Time average(vec::iterator b, vec::iterator e)
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
	vec v;
	v = make_vector(n);
	cout << "vec: " << endl;
	print_vector(v);

	// replace max elements
	s = *max_element(v.begin(), v.end());
	cout << "max = " << s << endl;
	replace_if(v.begin(), v.end(), Equal_s(), replace_value);
	cout << "replacing max with " << replace_value << endl;
	cout << "vec: " << endl;
	print_vector(v);

	// delete min elements
	s = *min_element(v.begin(), v.end());
	cout << "min = " << s << endl;
	auto i = remove_if(v.begin(), v.end(), Equal_s());
	//удалили элементы, начиная с i и до конца вектора
	v.erase(i, v.end());
	cout << "removing min element" << endl;
	cout << "vec: " << endl;
	print_vector(v);

	// sum average
	s = average(v.begin(), v.end());
	cout << "avg = " << s << endl;
	for_each(v.begin(), v.end(), sum_s);
	cout << "sum average for each element" << endl;
	cout << "vec: " << endl;
	print_vector(v);
}