#include "Time.h"
#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
using namespace std;

stack<Time>  reverse(stack<Time> s)
{
	stack<Time> temp;
	while (!s.empty())
	{
		temp.push(s.top());
		s.pop();
	}
	return temp;
}

stack<Time> makeS(int n)
{
	stack<Time> s;
	for (int i = 0; i < n; i++)
	{
		long num1 = rand() % 100;
		int num2 = rand() % 100;
		Time t(num1, num2);
		s.push(t);
	}
	return s;
}

void printV(stack<Time>& s)
{
	stack<Time> temp;
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		temp.push(s.top());
		s.pop();
	}
	s = temp;
	std::cout << "Size = " << s.size() << "\n\n";
}

void addMax(stack<Time>& s)
{
	Time max = s.top();
	stack<Time> temp;
	temp.push(s.top());
	s.pop();

	while (!s.empty())
	{
		if (max < s.top())
		{
			max = s.top();
		}
		temp.push(s.top());
		s.pop();
	}
	temp.push(max);
	s = temp;
}

void deleteMin(stack<Time>& s)
{
	Time min = s.top();
	stack<Time> temp;
	temp.push(s.top());
	s.pop();

	while (!s.empty())
	{
		if (min > s.top())
			min = s.top();
		temp.push(s.top());
		s.pop();
	}
	while (!temp.empty())
	{
		if (!(temp.top() == min))
			s.push(temp.top());
		temp.pop();
	}
	s = reverse(s);
}

void averageSum(stack<Time>& s)
{
	int size = s.size();
	Time sum(0, 0);
	stack<Time> temp;
	while (!s.empty())
	{
		sum = sum + s.top();
		temp.push(s.top());
		s.pop();
	}
	Time a = sum / size;
	cout << "average = " << a << endl;
	while (!temp.empty())
	{
		s.push(temp.top() + a);
		temp.pop();
	}
	s = reverse(s);
}

int main()
{
	srand(time(NULL));

	stack<Time> s;

	int n;
	cout << "Number of elements: ";
	cin >> n;
	if (n <= 0)
		return 0;

	s = makeS(n);	//создание стека
	printV(s);		//вывод

	addMax(s);		//добавить макс в начало
	printV(s);

	deleteMin(s);	//удалить мин
	printV(s);

	averageSum(s);	//+ ко всем среднего арифм.
	printV(s);

	system("pause");
}