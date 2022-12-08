#include "Student5.h"

Student::Student(void) : Person()
{
	mark = 0;
	pred = "";
}

Student::~Student(void)
{
}

Student::Student(string N, int A, string P, int M) : Person(N, A)
{
	pred = P;
	mark = M;
}

Student::Student(const Student& S)
{
	name = S.name;
	age = S.age;
	pred = S.pred;
	mark = S.mark;
}

void Student::SetPred(string P)
{
	pred = P;
}
void Student::SetMark(int M)
{
	mark = M;
}

string Student::GetPred()
{
	return pred;
}

int Student::GetMark()
{
	return mark;
}

Student& Student::operator=(const Student& s)
{
	if (&s == this)
		return *this;
	name = s.name;
	age = s.age;
	pred = s.pred;
	mark = s.mark;
	return *this;
}

istream& operator>>(istream& in, Student& s)
{
	cout << "\nName: "; in >> s.name;
	cout << "Age: "; in >> s.age;
	cout << "Pred: "; in >> s.pred;
	cout << "Mark: "; in >> s.mark;
	return in;
}

ostream& operator<<(ostream& out, const Student& s)
{
	out << "\n[out]:";
	out << "\nName: " << s.name;
	out << "\nAge: " << s.age;
	out << "\nPred: " << s.pred;
	out << "\nMark: " << s.mark;
	return out;
}

void Student::GetQuality()
{
	if (mark <= 2 and mark > -1)
		cout << "Оценка: Неудовлетворительно.\n";
	else if (mark >= 3 and mark < 6)
		cout << "Оценка: Норм.\n";
}

void Student::Show()
{
	cout << "\n[Show]: ";
    cout << "\nName: " << name;
    cout << "\nAge: " << age;
    cout << "\nPred: " << pred;
    cout << "\nMark: " << mark;
	cout << endl;
	GetQuality();
}