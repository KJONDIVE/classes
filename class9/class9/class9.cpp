#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	//контролируемый блок
	try
	{
		int ex[] = { 5, 3 };
		Vector x(2,ex);//вектор из двух элементов

		Vector y;//пустой вектор
		cout << "Вектор х = " << x << endl;//печать вектора х
		cout << "Индекс = ? ";
		int i;
		cin >> i;

		cout << "x[" << i << "] = " << x[i] << endl;

		cout << "y = x + 3" << endl;
		y = x + 3;
		cout << "y = " << y << endl;

		//удаление n элементов
		cout << "Попытка удалить 1 элемент из вектора X длиной 2" << endl;
		x = x - 1;
		cout << "x = " << x;

		cout << "Попытка удалить 2 элемент из вектора X длиной 1" << endl;
		x = x - 2;
		cout << "x = " << x;

	}
	//обработчик исключения
	catch (int e)
	{
		cout << "ERROR!!! Code: " << e << endl;
	}//сообщение об ошибке
	return 0;
}