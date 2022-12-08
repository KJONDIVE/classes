#include <iostream> 
#include <math.h> 
#include "Fract.h"
using namespace std;

int n;

Fract make_Fract(int F, int S)
{
	Fract t;
	t.Init(F, S);
	return t;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "...Переменные... \n";
	Fract A, B;
	cout << "Инициализация А... \n";
	A.Init(4, 2);
	cout << "Введите B: \n";
	B.Read();
	cout << "А: \n";
	A.Show();
	cout << "B: \n";
	B.Show();
	cout << "A.ipart(" << A.first << ", " << A.second << ")  = " << A.ipart() << endl; 
	cout << "B.ipart(" << B.first << ", " << B.second << ")  = " << B.ipart() << endl; 

	//указатели
	cout << "\n...Указатели... \n";
	Fract* X = new Fract;
	cout << "Инициализация X. \n";
	X->Init(5, 4);
	cout << "X: \n";
	X->Show();
	cout << "X.ipart(" << X->first << ", " << X->second << ") = " << X->ipart() << endl;

	//массивы
	cout << "\n...Массивы... \n";
	Fract arr[3];
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ": \n";
		arr[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ": \n";
		arr[i].Show();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "arr[" << i << "].ipart(" << arr[i].first << ", " << arr[i].second << ") = ";
		cout << arr[i].ipart() << endl;
	}

	//динам. массивы
	cout << "\n...Динамические массивы... \n";
	cout << "N = ";
	cin >> n;
	Fract* mas = new Fract[n];
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " элемент: \n";
		mas[i].Read();
	}
	cout << "Текущий массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " элемент: \n";
		mas[i].Show();
	}
	for (int i = 0; i < n; i++)
	{
		cout << "mas[" << i << "].ipart(" << mas[i].first << ", " << mas[i].second << ") = ";
		cout << mas[i].ipart() << endl;
	}
	//вызов функции
	cout << "\n...Вызов функции... \n";
	int x; 
	int y;
	cout << "First(): "; cin >> x;
	cout << "Second(): "; cin >> y;
	Fract F = make_Fract(x, y);
	cout << "Функция: \n";
	F.Show();
	cout << "F.ipart(" << F.first << ", " << F.second << ") = " << F.ipart();
}