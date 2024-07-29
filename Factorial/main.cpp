// Factorial

#include <iostream>
#include<locale.h>
#include<stdlib.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "---Программа вычисления факториала числа!---" << endl;
    //F=n!*(n-1)!
    int n = 0;//число, факториал кторого мы висляем
    unsigned int i = 1;// счетчик для перебора чисел от 1 n включительно
    // unsigned long long F = 1ull;//результат(факториал)
    double F = 1.0; //переменая для хранения результата, представленого экспоненициальной формы
    cout << "Введите число n, не больше 170 "; cin >> n;
    if (n > 170)cout << "Для вычисления факториала больше 170 используйте полную версию программы" << endl;
    else
        if (n < 0)cout << "Факториал не существуют!" << endl;
        else
            if (n == 0 || n == 1)cout << "Фактораил =1" << endl;
            else
            {
                while (i <= n)//от 1 до n включительно
                {
                    F *= i;//F=F*i
                    i++;
                    // cout << F << endl;//вывод промежуточного значения

                }
                cout << "факториал = " << F << endl;
            }

}
