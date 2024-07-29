// ArrayPointersFunctions
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

float Summa(float A, float B)
{
    return A + B;
}
float Raznost(float A, float B)
{
    return A - B;
}
float Proizvedenie(float A, float B)
{
    return A * B;
}
float Chastnoe(float A, float B)
{
    return A / B;
}
float Vyhod(float, float)
{
    cout << "Выход..." << endl;
    return 0.0F;
}

int main()
{
    system("chcp 1251");
    system("cls");
    //калькулятор через массив указателей на функции
    float A = 0.0F, B = 0.0F;
    int Select = 0; //индекс элемента массива(пункт меню)
    const int CountFunctions = 5;
    //создаем массив указателей на функции и инциализируем его адресами функций
    //float (*Calculator[CountFunctions])(float, float) = {Vyhod,Summa,Raznost,Proizvedenie,Chastnoe};
    //float (*Calculator[])(float, float) = { Vyhod,Summa,Raznost,Proizvedenie,Chastnoe }; //так тоже можно, размер будет взят по кол=-ву перечисленных функций

    //динамический массив указателей на функции

    typedef float(*PTRFunc)(float, float); //typedef - переопределение имени типа данных

    typedef unsigned long long UNSGLL; //typedef - переопределение имени типа данных


    int Count = 5;

    //UNSGLL Z = 15Ull;

    PTRFunc* Calculator = new PTRFunc[Count]{ Vyhod,Summa,Raznost,Proizvedenie,Chastnoe };


    auto PTR = Summa; //так сработает
    //auto CALC = { Vyhod,Summa,Raznost,Proizvedenie,Chastnoe }; //сработает, но не как массив

    //auto - автоматическое оперделение типа данных на основании типа данных содержимого(присваиваемого значения)

    auto X = 15;

    //auto ptr = nullptr; //так нельзя

    auto Z = 3.14;
    auto W = 3.14F;
    auto R = 0;

    R = 3.14; //R=3;


    do
    {
        system("cls");
        cout << "---Великий и могучий калькулятор!---" << endl;
        do
        {
            cout << R"(Выберите дейтсвие:
1. Сложение
2. Вычитание
3. Умножение
4. Деление
0. Выход
)";
            cin >> Select;
            if (Select < 0 || Select >= CountFunctions)cout << "Некорректный выбор действия! Попробуйте ещё раз!" << endl;
        } while (Select < 0 || Select >= CountFunctions);

        if (Select != 0)//если выбрано действие
        {
            system("cls");
            cout << "Введите число А: "; cin >> A;
            cout << "Введите число B: "; cin >> B;
            cout << "Результат равен: " << Calculator[Select](A, B) << endl;
        }
        else //если ноль то выход
        {
            Calculator[Select](A, B); //Calculator[0](A, B);
            break;
        }
        cout << "Для проджолжения вычислений нажмите любую клавишу..." << endl;
        _getch();  //int Z=_getch();
    } while (Select != 0);


    delete[] Calculator;
    Calculator = nullptr;
}