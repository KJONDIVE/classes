#include "Time.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef vector<Time> vec;

vec makeV(int n)
{
	vec v;
	for (int i = 0; i < n; i++)
	{
		long num1 = rand() % 100;
		int num2 = rand() % 60;
		Time t(num1, num2);
		v.push_back(t);
	}
	return v;
}

void printV(vec& v)
{
	int size = v.size();
	for (int i = 0; i < size; i++)
		cout << v[i] << " ";
	cout << endl;
}

void addMax(vec& v)
{
	Time max = v[0];

	for (int i = 0; i < v.size(); i++)
		if (max < v[i])
			max = v[i];

	v.insert(v.begin(), max);
}

void deleteMin(vec& v)
{
	Time min = v[0];
	int n = 0;

	for (int i = 0; i < v.size(); i++)
		if (min > v[i])
		{
			min = v[i];
			n = i;
		}
	v.erase(v.begin() + n);
}

void averageSum(vec& v)
{
	int sumMin = 0, sumSec = 0;
	for (int i = 0; i < v.size(); i++) {
		sumMin += v[i].getMin();
		sumSec += v[i].getSec();
	}
		
	Time a = Time(sumMin / v.size(), sumSec / v.size());
	cout << "average = " << a << endl;
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + a;
}

int main()
{
	srand(time(NULL));

	vec v;

	int n;
	cout << "Number of elements: ";
	cin >> n;
	if (n <= 0)
		return 0;
	v = makeV(n);
	printV(v);

	addMax(v);
	printV(v);

	deleteMin(v);
	printV(v);

	averageSum(v);
	printV(v);

	system("pause");
}