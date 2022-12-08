#include "Time.h"
#include <iostream>
#include <fstream>
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);	//������� ��� ������
	if (!stream.is_open())
		return -1;
	int n;
	Time m;
	cout << "Number of elements: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;									//���� ��������� ������� �� ������������ ������
		stream << m << "\n";						//������ ������� � �������� �����
	}
	stream.close();//������� �����
	return n;
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);				//������� ��� ������
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
	fstream temp("temp", ios::out);					//������� ��� ������
	fstream stream(f_name, ios::in);				//������� ��� ������
	if (!stream.is_open())
		return -1;
	int i = 0;
	Time m;
	while (stream >> m)								//���� ��� ����� ����� ��������� ������ �������
	{
		if (stream.eof())
			break;
		if (!(m == d))								//���� �� ������ �������
		{
			temp << m;
		}
		else
			i++;
	}
	stream.close();
	temp.close();
	remove(f_name);									//������� ������ ����
	rename("temp", f_name);							//������������� temp
	return i;										//���������� ���������
}

int add_file(const char* f_name, int k, int aft)
{
	fstream temp("temp", ios::out);			//������� ��� ������
	fstream stream(f_name, ios::in);		//������� ��� ������

	if (!stream.is_open())
		return -1;
	Time m;
	int i = 0;								//������� ���������
	int l = 0;								//������� �����������
	while (stream >> m)
	{
		if (stream.eof())
			break;
		i++;								//������ � 1
		if (i == aft)						//���� ������� ������ �����
		{
			temp << m;						//���������� ������� �������
			for (int j = 0; j < k; j++)
			{
				cin >> m;
				temp << m;					//�������� � temp ����� ������
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
	return l;								//���������� �����������
}

int add_end(const char* f_name, int k)
{
	fstream stream(f_name, ios::app);	//������� ��� ���������� � �����
	if (!stream.is_open())
		return -1;
	Time m;
	int i = 0;
	for (int j = 0; j < k; j++)
	{
		cin >> m;
		stream << m;					//�������� � temp ����� ������
		i++;
	}
	return i;							//��� �� �����������
}

int change_file(const char* f_name, const Time& m)
{
	fstream temp("temp", ios::out);			//������� ��� ������
	fstream stream(f_name, ios::in);		//������� ��� ������
	if (!stream.is_open())
		return -1;

	Time plus(3, 30);						//������ ��� ������������
	Time tempM;							//��������������� ������ ��� ������
	int i = 0;								//��� �� ����������
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
	return i;								//���������� ���������� ���������
}