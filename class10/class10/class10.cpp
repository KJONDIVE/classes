#include "Time.h"
#include "funcs.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	Time del, up;
	int r, step;												
	int n, k, aft;									   
	char fname[] = "C:\\Users\\leenz\\Desktop\\a.txt"; 
	do												   
	{													
		cout << "\n1. Make new file";
		cout << "\n2. Print file";
		cout << "\n3. Delete Time record from file (1)";
		cout << "\n4. Add K Time records to file after Position (3)";
		cout << "\n5. Add 3:30 to Time record (2)";
		cout << "\n10. Number of elements";
		cout << "\n0. Exit\n";
		cout << "\n-->Step: ";
		cin >> step;
		cout << endl;
		switch (step)
		{
		case 1:
			r = make_file(fname);
			if (r < 0)
				cout << "Can't make file\n";
			else
				cout << "Entered " << r << " elements\n";
			n = r;
			break;

		case 2:
			r = print_file(fname);
			if (r == 0)
				cout << "Empty file\n";
			if (r < 0)
				cout << "Can't read file\n";
			break;

		case 3:
			cout << "Delete this: \n";
			cin >> del;
			r = del_file(fname, del);
			if (r < 0)
			{
				cout << "Can't read file\n";
				break;
			}
			else
				cout << "Deleted " << r << " records\n";
			n -= r;
			break;

		case 4:
			cout << "Number of elements: "; cin >> k;
			cout << "Add after: "; cin >> aft;
			r = add_file(fname, k, aft);
			if (r < 0)
			{
				cout << "Can't read file\n";
				break;
			}
			if (r == 0)
			{
				cout << "Not such number; Add to the end.\n";
				r = add_end(fname, k);
			}
			n += r;
			break;

		case 5:
			cout << "Sum 3:30 to this: \n";
			cin >> up;
			r = change_file(fname, up);
			if (r < 0)
				cout << "Can't read file\n";
			if (r == 0)
				cout << "Not such record\n";
			else
				cout << "Updated " << r << " elements\n";
			break;

		case 10:
			cout << "Elements = " << n << endl;
			break;

		}
	} while (step != 0);
}