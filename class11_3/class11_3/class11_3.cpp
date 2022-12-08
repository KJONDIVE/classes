#include "Vector.h"
#include "Time.h"
using namespace std;

typedef Vector<Time> vec;

int main()
{
	srand(time(NULL));

	int n;
	cout << "Number of elements: ";
	cin >> n;

	vec v(n);
	v.printV();

	v.addMax();
	v.printV();

	v.deleteMin();
	v.printV();

	v.averageSum();
	v.printV();

	system("pause");
}