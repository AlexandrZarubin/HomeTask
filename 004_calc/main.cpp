// Calculator2.0.
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <math.h> //математическая библиотека

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    double A = 0.0, B = 0.0, Result = 0.0;
    char Key = '+';
    //цикл многократных вычислений
    do
    {
        system("cls");
        cout << "---Самый Лучший в мире калькулятор!---" << endl;

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
            Result = A + B;
            cout << "Результат равен: " << Result << endl;
            break;
        default:
            cout << "Некорректное действие!" << endl;
            break;
        case '-':
            Result = A - B;
            cout << "Результат равен: " << Result << endl;
            break;
        case '*':
            Result = A * B;
            cout << "Результат равен: " << Result << endl;
            break;
        case '/':
            if (B == 0) cout << "Делить на ноль нельзя!!!" << endl;
            else
            {
                Result = A / B;
                cout << "Результат равен: " << Result << endl;
            }
            break;
        case '^':
            Result = pow(A, B); //число А в степени В //pow(R,2);
            cout << "Результат равен: " << Result << endl;
            break;
            //перечисляем все case для которых нужно выполнить одинаковые действия
        case 'v':
            cout << "Вы ввели строчную букву v!" << endl; //уникальное дейтсвие для case 'v'
        case 'V':
            //общие действия для case 'v' и 'V'
            Result = pow(B, 1 / A); //корень А-ой степени из числа В
            cout << "Результат равен: " << Result << endl;
            break; //последний break можно не писать
        }
        //вопрос о продолжений вычислений
        cout << "Продолжить вычисления(Y/N)?"; cin >> Key;
    } while (Key == 'Y' || Key == 'y');//цикл работает пока пользователь отвечает да вопрос о продолжений
    //system("pause");

}