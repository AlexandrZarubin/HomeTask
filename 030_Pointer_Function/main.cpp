// PointerFunction
#include <iostream>
#include <stdlib.h>

using namespace std;

void Function()
{
    cout << "Выполняется функция Function!" << endl;
}

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

int main()
{
    system("chcp 1251");
    system("cls");
    /*
    Function (); //вызов функции по её имени с использованием оператора вызова функции ()

    //получение адреса функции через оператор взятия адреса
    cout << "Адрес функции Function: " << &Function << endl;

    //получение адреса функции по её имени(имя функции - указатель, хранящий адрес начала функции в памяти)
    cout << "Адрес функции Function: " << Function << endl;

    //Function = nullptr; //имя функции это константный указатель

    //system("cls");

    //объявляем указатель на функцию без параметров и без возвращаемого результата
    void (*ptrFunction)() = nullptr; //нульвой указатель на функцию

    ptrFunction = Function; //ptrFunction = &Function; //передаем адрес функции в указатель

    *ptrFunction; //вызова функции не будет, а будет получен адрес функции
    cout << "Адрес функции Function: " << *ptrFunction << endl;
    cout << "Адрес функции Function: " << ptrFunction << endl;
    (*ptrFunction)(); //вызов функции Function через её адрес, полеченный путем разыменования указателя ptrFunction

    ptrFunction(); //вызывов функции через указатель на неё
    system("cls");
    */


    float A = 0.0F, B = 0.0F;
    char Key = '+';

    //нулевой указатель на функции
    float (*calc)(float, float) = nullptr;
    do
    {
        system("cls");
        cout << "---Самый высокотехнологичный калькулятор!---" << endl;

        //1 вариант меню
    //    cout << "Введите число А: "; cin >> A;
    //    cout << R"(
    //Выберите действие:
    //'+' - Сложение
    //'-' - Вычитание
    //'*' - Умножение
    //'/' - Деление
    //'^' - Число А в степени В
    //'V' - Корень А-ой степени из В
    //)";
    //    cin >> Key; //ввод символа действия
    //    cout << "\nВведите число В: "; cin >> B;

        //2 вариант меню
        cout << R"(
Используйте действия по образцу:
Сложение:                    А+В
Вычитание:                   А-В
Умножение:                   А*В
Деление:                     А/В
Возведение А в степень В:    А^В
Корень А-ой степени из В:    АVB
)";
        //множественный ввод
        cin >> A >> Key >> B; //15+9   //double char double //int int int  3 4 5

        //конструкция множественного выбора
        switch (Key)
        {
        case '+':
            calc = Summa; //присваиваем в указатель адрес функции Summa
            break;
        case '-':
            calc = Raznost; //присваиваем в указатель адрес функции Raznost
            break;
        case '*':
            calc = Proizvedenie; //присваиваем в указатель адрес функции Proizvedenie
            break;
        case '/':
            calc = Chastnoe; //присваиваем в указатель адрес функции Chastnoe
            break;
        default:
            Key = '0';
            break;
        }
        if (Key != '0') cout << "Результат равен: " << calc(A, B) << endl;
        else cout << "Некорректное действие!" << endl;
        //вопрос о продолжении вычислений
        cout << "Продолжить вычисления (Y/N)? "; cin >> Key;
    } while (Key == 'Y' || Key == 'y'); //цикл работает пока пользователь отвечает да вопрос о продолжении   
}
