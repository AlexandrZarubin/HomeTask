// Debugger

#include <iostream>
#include<locale.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    //int A = 0, B = 0;
    //cout << "Введите число А:"; cin >> A;
    //do //цикл проверки пользовательскокго ввода 
    //{
    //    cout << "Введите число B, не равное 0: ";
    //    cin >> B;
    //} while (B == 0);
    //double C = (double)A / B;
    //cout << "Результат С= "<<C<<endl;


    /*for (int i = 0; i < 100; i++)
    {
        cout << i << "*" << i << "= " << i * i << endl;
    }*/

    int i = 0;
    for (; i < 4; i++) //0 1 2 3 выход 4 
    {
        switch (i)
        {
        case 0: cout << "0";
        case 1: cout << "1";
            continue;
        case 2: cout << "2";
            break;
        default: cout << "D";
            break;
        }
        cout << ".";
    }


}
