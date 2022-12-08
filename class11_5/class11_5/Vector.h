#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template<class T>
class Vector
{
	stack <T> s;//���������
	int size;//������ ����������
public:
	Vector();//����������� ��� ����������
	Vector(int n);//����������� � �����������
	Vector(const Vector<T>&);//����������� �����������
	void printV();		//������
	void addMax();		//�������� ���� ������� � ������
	void deleteMin();	//������� ��� �������
	void averageSum();	//+ �� ���� ��������� ������� �����.
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

//����������� ����� � ������
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
//����������� ������� � ����
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

//����������� ��� ����������
template <class T>
Vector<T>::Vector()
{
	size = 0;
}
//����������� � ����������
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//�������� � ���� ������� �
	}
	size = s.size();
}
//����������� �����������
template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	//�������� �������� ����� Vec.s � ������ v
	vector v = copy_stack_to_vector(Vec.s);
	size = v.len;
	//�������� ������ v � ���� s
	s = copy_vector_to_stack(v);
}
//������
template <class T>
void Vector<T>::printV()
{
	//�������� ���� � ������
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//���� ���� �� ������
	{
		cout << s.top() << " ";//����� �������� � ������� �����
		s.pop();//������� ������� �� �������
	}
	cout << endl;
	//�������� ������ � ����
	s = copy_vector_to_stack(v);
}

template<class T>
void Vector<T>::addMax()
{
	//�������� ���� � ������
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
	//�������� ���� � ������
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

	//�������� ������ � ����
	s = copy_vector_to_stack(v);
	
}

template<class T>
void Vector<T>::averageSum()
{
	// �������� ���� � ������
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
