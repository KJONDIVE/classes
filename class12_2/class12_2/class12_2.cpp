#include <iostream>
#include <map>
#include "Time.h"
using namespace std;

typedef multimap<int, Time>TMap;//определяем тип для работы со словарем

//функция для формирования словаря
TMap make_map(int n)
{
	TMap m;//пустой словарь
	Time v;
	int k;
	for (int i = 0; i < n; i++)
	{
		cout << i << " Key ? = ";
		cin >> k;
		cout << "Value ? = ";
		cin >> v;
		//создаем пару и добавляем ее в словарь
		m.insert(make_pair(k, v));
	}
	return m;//возвращаем словарь как результат работы функции
}
//функция для печати словаря
void print_map(TMap m)
{
	for (TMap::iterator iter = m.begin(); iter != m.end(); ++iter)
		cout << iter->first << " : " << iter->second << " " << endl;

}


pair<int, Time> find_max(TMap v)
{
	auto i = v.begin();
	int nom = 0,//номер максимального
		k = 0;//счетчик элементов
	pair<int, Time> max = *i;;
	Time m = (*i).second;//значение первого элемента
	while (i != v.end())
	{
		if (m < (*i).second)
		{

			m = (*i).second;
			nom = k;
			max = *i;
		}
		i++;//итератор
		k++;//счетчик элементов
	}
	
	return max;//номер max
}

pair<int, Time> find_min(TMap v)
{
	auto i = v.begin();
	int nom = 0,//номер максимального
		k = 0;//счетчик элементов
	pair<int, Time> min = *i;
	Time m = (*i).second;//значение первого элемента
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			nom = k;
			min = *i;
		}
		i++;//итератор
		k++;//счетчик элементов
	}
	return min;//номер max
}
void add_avg(TMap& m)
{
	Time avg;
	for (TMap::iterator iter = m.begin(); iter != m.end(); ++iter)
	{
		avg = avg + iter->second;
	}
	avg = avg / m.size();

	for (TMap::iterator iter = m.begin(); iter != m.end(); ++iter)
	{
		iter->second = iter->second + avg;
	}

}

void add_max(TMap& v)
{
	auto max_pair = find_max(v);

	v.insert(v.begin(), max_pair);
}

void remove_min(TMap& v) {
	auto min_pair = find_min(v);
	//cout << min_pair.first << " - " << min_pair.second << endl;
	auto pos_iter = v.find(min_pair.first);
	v.erase(++pos_iter);
}

//основная функция
int main()
{
	int n;
	cout << "N?"; cin >> n;//количество элементов
	TMap m = make_map(n);//создать словарь
	cout << "m = " << endl;
	print_map(m);//напечатать словарь

	cout << "insert max" << endl;
	add_max(m);
	cout << "m = " << endl;
	print_map(m);

	cout << "remove min " << endl;
	remove_min(m);
	cout << "m = " << endl;
	print_map(m);

	cout << "sum avg = " << endl;
	add_avg(m);
	cout << "m = " << endl;
	print_map(m);
}