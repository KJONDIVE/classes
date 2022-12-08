#include<string>

using namespace std;

class Student
{
	string FIO;
	string Group;
	float AvgMark;

public:
	Student(); //конструктор по умолчанию
	Student(string, string, float); //конструктор с параметрами 
	Student(const Student&); //конструктор копирования
	~Student(); //деструктор

	//селекторы и модификаторы
	string Get_FIO();
	void Set_FIO(string);
	string Get_Group();
	void Set_Group(string);
	float Get_AvgMark();
	void Set_AvgMark(float);

	void Show();
};