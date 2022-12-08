#include "Time.h"
#include <iostream>
#include <fstream>
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);	//открыть для записи
	if (!stream.is_open())
		return -1;
	int n;
	Time m;
	cout << "Number of elements: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;									//ввод атрибутов объекта из стандартного потока
		stream << m << "\n";						//запись объекта в файловый поток
	}
	stream.close();//закрыть поток
	return n;
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);				//открыть для чтения
	if (!stream.is_open())
		return -1;
	Time m;
	int i = 0;
	while (stream >> m)
	{
		i++;
		cout << "  " << i << " -  " << m << "\n";
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, const Time& d)
{
	fstream temp("temp", ios::out);					//открыть для записи
	fstream stream(f_name, ios::in);				//открыть для чтения
	if (!stream.is_open())
		return -1;
	int i = 0;
	Time m;
	while (stream >> m)								//пока нет конца файла выполняем чтение объекта
	{
		if (stream.eof())
			break;
		if (!(m == d))								//если не нужный элемент
		{
			temp << m;
		}
		else
			i++;
	}
	stream.close();
	temp.close();
	remove(f_name);									//удалить старый файл
	rename("temp", f_name);							//переименовать temp
	return i;										//количество удаленных
}

int add_file(const char* f_name, int k, int aft)
{
	fstream temp("temp", ios::out);			//открыть для записи
	fstream stream(f_name, ios::in);		//открыть для чтения

	if (!stream.is_open())
		return -1;
	Time m;
	int i = 0;								//счетчик элементов
	int l = 0;								//счетчик добавленных
	while (stream >> m)
	{
		if (stream.eof())
			break;
		i++;								//отсчет с 1
		if (i == aft)						//если нашелся нужный номер
		{
			temp << m;						//записываем текущий элемент
			for (int j = 0; j < k; j++)
			{
				cin >> m;
				temp << m;					//записать в temp новую запись
				l++;
			}
		}
		else
			temp << m;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;								//количество добавленных
}

int add_end(const char* f_name, int k)
{
	fstream stream(f_name, ios::app);	//открыть для добавления в конец
	if (!stream.is_open())
		return -1;
	Time m;
	int i = 0;
	for (int j = 0; j < k; j++)
	{
		cin >> m;
		stream << m;					//записать в temp новую запись
		i++;
	}
	return i;							//кол во добавленных
}

int change_file(const char* f_name, const Time& m)
{
	fstream temp("temp", ios::out);			//открыть для записи
	fstream stream(f_name, ios::in);		//открыть для чтения
	if (!stream.is_open())
		return -1;

	Time plus(3, 30);						//объект для суммирования
	Time tempM;							//вспомогательный объект для записи
	int i = 0;								//кол во измененных
	while (stream >> tempM)
	{
		if (stream.eof())
			break;
		if (tempM == m)
		{
			tempM = tempM + plus;
			temp << tempM;
			i++;
		}
		else
			temp << tempM;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;								//количество измененных элементов
}