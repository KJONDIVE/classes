#include <iostream>
#include <Windows.h>
#include "Time.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Time A;
    cout << "A = " << A << endl;

    Time B(14, 25);
    cout << "B = " << B << endl;

    Time C = B; 
    cout << "C = " << C << endl;

    Time D;
    cin >> D;
    cout << "D = " << D << endl;

    Time E = D + C;
    cout << "E = сумма D и C: \n";
    cout << "E = "<< E << endl;

    Time F;
    cout << "Введите время F для сравнения с E\n";
    cin >> F;
    cout << "F == E = " << (F == E);
    cout << endl;

}