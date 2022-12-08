#include "Time.h"
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<Time> vec;
typedef stack<Time> stck;
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

vec copy_stack_to_vector(stck s)
{
	vec v;
	while (!s.empty())//пока стек не пустой
	{
		//добавить в вектор элемент из вершиы стека
		v.push_back(s.top());
		s.pop();
	}
	return v; //вернуть вектор как результат функции
}
//копирует вектор в стек
stck copy_vector_to_stack(vec v)
{
	stck s;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		s.push(v[i]);//добавить в стек элемент вектора
	}
	return s; //вернуть стек как результат функции
}


//формирование стека
stck make(int n)
{
	Time a;
	stck v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push(a);
	}
	return v;
}

//печать
void print(stck v)
{
	while (!v.empty())
	{
		cout << v.top() << endl;
		v.pop();
	}

	cout << endl;
}

Time average(stck v)
{
	Time s = Time(0, 0);
	int n = 0;
	//перебор вектора
	while (!v.empty()) {
		s = s + v.top();
		n++;
		v.pop();
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
	stck v;
	vec tmp_v;
	v = make(n);
	cout << "stack: " << endl;
	print(v);

	// replace max elements
	tmp_v = copy_stack_to_vector(v);
	s = *max_element(tmp_v.begin(), tmp_v.end());
	cout << "max = " << s << endl;
	replace_if(tmp_v.begin(), tmp_v.end(), Equal_s(), replace_value);
	cout << "replacing max with " << replace_value << endl;
	cout << "stack: " << endl;
	v = copy_vector_to_stack(tmp_v);
	print(v);

	// delete min elements
	tmp_v = copy_stack_to_vector(v);
	s = *min_element(tmp_v.begin(), tmp_v.end());
	cout << "min = " << s << endl;
	auto i = remove_if(tmp_v.begin(), tmp_v.end(), Equal_s());
	//удалили элементы, начиная с i и до конца вектора
	tmp_v.erase(i, tmp_v.end());
	cout << "removing min element" << endl;
	cout << "stack: " << endl;
	v = copy_vector_to_stack(tmp_v);
	print(v);

	// sum average
	tmp_v = copy_stack_to_vector(v);
	s = average(v);
	cout << "avg = " << s << endl;
	for_each(tmp_v.begin(), tmp_v.end(), sum_s);
	cout << "sum average for each element" << endl;
	cout << "stack: " << endl;
	v = copy_vector_to_stack(tmp_v);
	print(v);
}