#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef vector<double> vec;

vec makeV(int n)
{
	vec v;
	for (int i = 0; i < n; i++)
	{
		double num1 = (double(rand() % 100)) / 100;
		int num2 = rand() % 100;
		double res = num1 + num2;
		v.push_back(res);
	}
	return v;
}

void printV(vec& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

void addMax(vec& v)
{
	double max = v[0];

	for (int i = 0; i < v.size(); i++)
		if (max < v[i])
			max = v[i];

	v.insert(v.begin(), max);
}

void deleteMin(vec& v)
{
	double min = v[0];
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
	double sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += v[i];
	double a = sum / v.size();
	cout << "average = " << a << endl;
	for (int i = 0; i < v.size(); i++)
		v[i] += a;
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
	v = makeV(n);	//создание вектора
	printV(v);		//вывод

	cout << "Add max: ";
	addMax(v);		//добавить максимум в начало вектора
	printV(v);

	cout << "Delete min: ";
	deleteMin(v);	//удалить минимум из вектора
	printV(v);

	cout << "Sum avg: ";
	averageSum(v);	//добавить среднее арифметическое 
	printV(v);		//ко всем элементам вектора

	system("pause");
}