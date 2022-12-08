#include<string>

using namespace std;

class Student
{
	string FIO;
	string Group;
	float AvgMark;

public:
	Student(); //����������� �� ���������
	Student(string, string, float); //����������� � ����������� 
	Student(const Student&); //����������� �����������
	~Student(); //����������

	//��������� � ������������
	string Get_FIO();
	void Set_FIO(string);
	string Get_Group();
	void Set_Group(string);
	float Get_AvgMark();
	void Set_AvgMark(float);

	void Show();
};