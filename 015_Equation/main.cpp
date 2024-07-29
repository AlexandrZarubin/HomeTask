// Equation
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>

using namespace std;
//функция решения квадратного уравнения и линейного уравнения, как
//частного случая квадратного уравнения, возвращает кол-во корней
//int Uravnenie(double a, double b, double c) //первый вариант
int Uravnenie(double b, double c, double a = 0.0) //второй вариант с параметром по умолчанию
{
    double x1 = 0.0, x2 = 0.0, D = 0.0;
    if (a == 0.0) //если уравненеи линейное
    {
        //bx+c=0;
        x1 = -c / b;
        cout << "x1= " << x1 << endl;
        return 1; //возвращает кол-во корней
    }
    //else //можно не писать
    D = pow(b, 2) - 4 * a * c;
    if (D < 0.0)
    {
        cout << "Нет действительных корней!" << endl;
        return 0;
    }
    //else //можно не писать
    if (D == 0.0) //два одинаковых корня
    {
        x1 = (-b) / (2 * a);
        //x2 = x1;
        cout << "x1=x2= " << x1 << endl;
        return 20; //два одинаковых корня
    }
    //else //можно не писать
    x1 = ((-b) - sqrt(D)) / (2 * a);
    x2 = ((-b) + sqrt(D)) / (2 * a);
    cout << "x1= " << x1 << "\nx2= " << x2 << endl;
    return 2; //два разных корня
}

//функция для решения линейного уравнения
inline double Equation(double k, double b)//inline - просьба компилятора встроить функцию
{
    //kx+b=0;
    cout << "x= " << -b / k << endl; //для работы по аналогии с функцией Uravneie
    return -b / k;
}
//перегрузка функции для решения квадратного уравнения
int Equation(double a, double b, double c)
{
    double x1 = 0.0, x2 = 0.0, D = 0.0;
    if (a == 0.0)
    {
        Equation(b, c); // cout << "x= " << -b / k << endl;
        return -1; //обзначение, что была вызвана функция рпешения линейного уравнения
    }
    //else //можно не писать
    D = pow(b, 2) - 4 * a * c;
    if (D < 0.0)
    {
        cout << "Нет действительных корней!" << endl;
        return 0;
    }
    //else //можно не писать
    if (D == 0.0) //два одинаковых корня
    {
        x1 = (-b) / (2 * a);
        //x2 = x1;
        cout << "x1=x2= " << x1 << endl;
        return 20; //два одинаковых корня
    }
    //else //можно не писать
    x1 = ((-b) - sqrt(D)) / (2 * a);
    x2 = ((-b) + sqrt(D)) / (2 * a);
    cout << "x1= " << x1 << "\nx2= " << x2 << endl;
    return 2; //два разных корня
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choise = 0;
    double a = 0.0, b = 0.0, c = 0.0, k = 0.0;
    do //цикл повторных вычислений
    {
        cout << R"(---Программа для решения уравнений!---
1 - Линейное уравнение (kx+b=0)
2 - Квадратное уравнение (ax^2+bx+c=0)
0 - Выход из программы
)";
        do //цикл проверки пользовательского ввода
        {
            cout << "Выберите тип уравнения: "; cin >> choise;
            if (choise < 0 || choise>2)cout << "Неправильно выбран тип уравнения! Попробуйте ещё раз!" << endl;
        } while (choise < 0 || choise>2);
        if (choise == 0)break; //выход из программы(из цикла повторных вычислений)
        switch (choise)
        {
        case 1:
            cout << "Введите коэффициент k: "; cin >> k;    //cin >> b;
            cout << "Введите коэффициент b: "; cin >> b;    //cin >> c;
            //a = 0.0; //обнуляем а, если перед этим решали квадратное уравнение, для первого варианта
            //Uravnenie(0.0, k, b); //Uravnenie(0.0, b, c); //Uravnenie(a, b, c); //первый вариант
            //Uravnenie(k, b); //Uravnenie(b, c);
            //вариант с перегрузкой функции
            Equation(k, b); //Equation(b, c); 
            break;
        case 2:
            cout << "Введите коэффициент a: "; cin >> a;
            cout << "Введите коэффициент b: "; cin >> b;
            cout << "Введите коэффициент c: "; cin >> c;
            //первый вариант
            //Uravnenie(a, b, c);
            //второй вариант с параметром по умолчанию
            //Uravnenie(b, c, a);
            //вариант с перегрузкой функции
            Equation(a, b, c);
            break;
        }
        system("pause");
        system("cls");
    } while (choise != 0);
    cout << "Выход..." << endl;
    Sleep(1500);
}
