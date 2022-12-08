#include "List.h"

Vector::~Vector()
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
//����������� � �����������
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}


//���������� �������, �� ������� ��������� ��������� p � ������
void Vector::Add()
{
	Object* p;
	//����� �� �������� ���� ��������� �������
	cout << "1.Person" << endl;
	cout << "2.Student" << endl;
	int y;
	cin >> y;
	if (y == 1)//���������� ������� ������ Person
	{
		Person* a = new (Person);
		a->Input();//���� �������� ���������
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//���������� � ������
			cur++;
		}
	}
	else
		if (y == 2) //���������� ������� ������ Student
		{
			Student* b = new Student;
			b->Input();
			p = b;
			if (cur < size)

			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;

}
//�������� �������

void Vector::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//��������� �� ��������� ���� Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//����� ������ Show() (������� ����������)
		p++;//����������� ��������� �� ��������� ������

	}
}
void Vector::Show(int i)
{
	Object* elem = NULL;
	if (i >= 0 && i < cur) {
		Object* elem = *beg;
		while (i != 0) {
			elem++;
			i--;
		}
		elem->Show();
	}
	else {
		cout << "NULL" << endl;
	}
	
}
//��������, ������� ���������� ������ �������
int Vector::operator ()()
{
	return cur;
}
Object* Vector::operator[](int i)
{
	if (i < 0 || i >= size) {
		return NULL;
	}
	Object* elem = *beg;
	while (i != 0) {
		elem++;
	}
	return elem;
}
//�������� �������� �� �������, ������ �� �������������!
void Vector::Del()
{
	if (cur == 0)return;//������
	cur--;
}