#include "List.h"

Vector::~Vector()
{
	if (beg != 0)delete[] beg;
	beg = 0;
}
//конструктор с параметрами
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}


//добавление объекта, на который указывает указатель p в вектор
void Vector::Add()
{
	Object* p;
	//выбор из объектов двух возможных классов
	cout << "1.Person" << endl;
	cout << "2.Student" << endl;
	int y;
	cin >> y;
	if (y == 1)//добавление объекта класса Person
	{
		Person* a = new (Person);
		a->Input();//ввод значений атрибутов
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор
			cur++;
		}
	}
	else
		if (y == 2) //добавление объекта класса Student
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
//просмотр вектора

void Vector::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//указатель на указатель типа Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//вызов метода Show() (позднее связывание)
		p++;//передвигаем указатель на следующий объект

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
//операция, которая возвращает размер вектора
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
//удаление элемента из вектора, память не освобождается!
void Vector::Del()
{
	if (cur == 0)return;//пустой
	cur--;
}