#pragma once
#include <iostream>
#include <map> //�������
using namespace std;
//������������������� �����
template<class T>
class Container
{
	multimap<int, T> m; //��������� �������
	int len; //����� �������
public:
	Container(void); //����������� ��� ����������
	Container(int n); //����������� � �����������
	void Print(); //������
	~Container(void); //����������

	void AddMax();
	void RemoveMin();
	void SumAvg();

private:
	pair<int, T> FindMax();
	pair<int, T> FindMin();
};
//���������� �������
//����������� ��� ����������
template <class T>
Container<T>::Container()

{
	len = 0;
}
//����������
template <class T>
Container<T>::~Container(void)
{
}
//����������� c �����������
template <class T>
Container<T>::Container(int n)
{
	T v;
	int k;
	for (int i = 0; i < n; i++)
	{
		cout << i << " Key ? = ";
		cin >> k;
		cout << "Value ? = ";
		cin >> v;

		m.insert(make_pair(k, v));
	}
	len = m.size();
}
//����� ����������
template <class T>
void Container<T>::Print()
{
	for (auto iter = m.begin(); iter != m.end(); ++iter)
		cout << iter->first << " : " << iter->second << " " << endl;
	cout << endl;
}

template <class T>
pair<int, T> Container<T>::FindMax()
{
	auto i = m.begin();
	int nom = 0,//����� �������������
		k = 0;//������� ���������
	pair<int, T> max = *i;;
	T elem = (*i).second;//�������� ������� ��������
	while (i != m.end())
	{
		if (elem < (*i).second)
		{

			elem = (*i).second;
			nom = k;
			max = *i;
		}
		i++;//��������
		k++;//������� ���������
	}

	return max;//����� max
}

template <class T>
pair<int, T> Container<T>::FindMin()
{
	auto i = m.begin();
	int nom = 0,//����� �������������
		k = 0;//������� ���������
	pair<int, T> min = *i;
	T elem = (*i).second;//�������� ������� ��������
	while (i != m.end())
	{
		if (elem > (*i).second)
		{
			elem = (*i).second;
			nom = k;
			min = *i;
		}
		i++;//��������
		k++;//������� ���������
	}
	return min;//����� max
}

template <class T>
void Container<T>::SumAvg()
{
	T avg;
	for (auto iter = m.begin(); iter != m.end(); ++iter)
	{
		avg = avg + iter->second;
	}
	avg = avg / m.size();

	for (auto iter = m.begin(); iter != m.end(); ++iter)
	{
		iter->second = iter->second + avg;
	}

}

template <class T>
void Container<T>::AddMax()
{
	auto max_pair = FindMax();

	m.insert(m.begin(), max_pair);
}

template <class T>
void Container<T>::RemoveMin() {
	auto min_pair = FindMin();

	auto pos_iter = m.find(min_pair.first);
	m.erase(++pos_iter);
}