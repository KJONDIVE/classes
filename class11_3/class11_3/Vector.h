#pragma once
#include <vector>
#include <iostream>
using namespace std;
//������ ������
template<class T>
class Vector
{
	vector <T> v;//���������������� ��������� ��� �������� ��������� �������
	int size;
public:
	Vector(void);//����������� ��� ���������
	Vector(int n);//����������� � ����������
	void printV();		//������
	void addMax();		//�������� ���� ������� � ������
	void deleteMin();	//������� ��� �������
	void averageSum();	//+ �� ���� ��������� ������� �����.
	~Vector(void);//����������
};

//����������� ��� ���������
template <class T>
Vector<T>::Vector()
{
	size = 0;
}
//����������
template <class T>
Vector<T>::~Vector(void)

{
}
//����������� � ����������
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	size = v.size();
}
//������
template <class T>
void Vector<T>::printV()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}


template<class T>
void Vector<T>::addMax()
{
	T max = v[0];

	for (int i = 0; i < size; i++)
		if (max < v[i])
			max = v[i];

	v.insert(v.begin(), max);
	size++;
}

template<class T>
void Vector<T>::deleteMin()
{
	T min = v[0];
	int n = 0;

	for (int i = 0; i < size; i++)
		if (min > v[i])
		{
			min = v[i];
			n = i;
		}
	v.erase(v.begin() + n);
	size--;
}

template<class T>
void Vector<T>::averageSum()
{
	T sum = T();
	for (int i = 0; i < size; i++)
		sum = sum + v[i];
	T a = sum / size;
	cout << "average = " << a << endl;
	for (int i = 0; i < size; i++)
		v[i] = v[i] + a;
}