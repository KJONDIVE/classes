#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template<class T>
class Vector
{
	stack <T> s;//контейнер
	int size;//размер контейнера
public:
	Vector();//конструктор без параметров
	Vector(int n);//конструктор с параметрами
	Vector(const Vector<T>&);//конструктор копирования
	void printV();		//печать
	void addMax();		//добавить макс элемент в начало
	void deleteMin();	//удалить мин элемент
	void averageSum();	//+ ко всем элементам среднее арифм.
};

template<class T>
stack<T> reverse(stack<T> S)
{
	stack<T> temp;
	while (!S.empty())
	{
		temp.push(S.top());
		S.pop();
	}
	return temp;
}

//копирование стека в вектор
template <class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;

	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}
//копирование вектора в стек
template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		//cout << "copy " << i << " " << v[i] << endl;
		s.push(v[i]);
	}
	return s;
}

//конструктор без параметров
template <class T>
Vector<T>::Vector()
{
	size = 0;
}
//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//добавить в стек элемент а
	}
	size = s.size();
}
//конструктор копирования
template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	//копируем значения стека Vec.s в вектор v
	vector v = copy_stack_to_vector(Vec.s);
	size = v.len;
	//копируем вектор v в стек s
	s = copy_vector_to_stack(v);
}
//печать
template <class T>
void Vector<T>::printV()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		cout << s.top() << " ";//вывод элемента в вершине стека
		s.pop();//удаляем элемент из вершины
	}
	cout << endl;
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
}

template<class T>
void Vector<T>::addMax()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);

	T max = v[0];

	for (int i = 0; i < size; i++)
		if (max < v[i])
			max = v[i];

	v.insert(v.begin(), max);
	size++;
	s = copy_vector_to_stack(v);
	/*cout << s.size() << endl;*/
}

template<class T>
void Vector<T>::deleteMin()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);

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

	//копируем вектор в стек
	s = copy_vector_to_stack(v);
	
}

template<class T>
void Vector<T>::averageSum()
{
	// копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);

	T sum = T();
	for (int i = 0; i < size; i++)
		sum = sum + v[i];

	T a = sum / size;
	cout << "average = " << a << endl;

	for (int i = 0; i < size; i++)
		v[i] = v[i] + a;
	
	s = copy_vector_to_stack(v);
}
