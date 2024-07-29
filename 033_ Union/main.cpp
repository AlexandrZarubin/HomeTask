// Union1

#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include "c:/YandexDisk/WorksStudy/Header/Date1.h" //подключение собственного заголовочного файла по полному пути
#include "C:/YandexDisk/WorksSrudyV2/Git_project/HomeTask/032_Struct/Data.h"
//using namespace std;

//struct Store
union Store //объединие
{
    double number;  //вещественное число
    int digit;      //целое число
    char symbol;    //символ
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(nullptr));

    /* Date Yesterday{};
     cout << "Размер структуры Date: " << sizeof(Date) << endl;
     cout << "Размер объекта структуры Date: " << sizeof(Yesterday) << endl;
     cin >> Yesterday.Month;
     Show(Yesterday);
     cout << "Размер объекта структуры Date: " << sizeof(Yesterday) << endl;
     */

     /* cout << "Размер структуры Store: " << sizeof(Store) << endl;
      Store Object{};
      Object.number = 3.14;
      cout << "Поля структуры Store: " << Object.number << " " << Object.digit << " " << Object.symbol << endl;
      Object.digit = 123;
      cout << "Поля структуры Store: " << Object.number << " " << Object.digit << " " << Object.symbol << endl;
      Object.symbol = 'Ю';
      cout << "Поля структуры Store: " << Object.number << " " << Object.digit << " " << Object.symbol << endl;
      cout << "Поля структуры Store:\n" << &Object.number << "\n" << &Object.digit << "\n" << (int*)&Object.symbol << endl;
      */


      //массив из 10 объектов объединения Store, каждый из которых может хранить или double или int или char
    Store Array[10]{};
    Array[0].digit = 15;
    Array[1].number = 3.14;
    Array[2].symbol = 'Ю';

    cout << Array[0].digit << endl;
    cout << Array[1].number << endl;
    cout << Array[2].symbol << endl;


    int Types[10]{}; //массив хранящий типы данных элементов массива Store

    //при работе с объединением нам доступно только одно поле в один момент времени
    enum Types { Double = 1, Int = 2, Char = 3 };
    for (int i = 0; i < 10; i++)
    {
        Types[i] = rand() % 3 + 1;//от 1 до 3 //можно вводить с клавиатуры
        //"Выберите тип данных 1 - double, 2 - int, 3 - char"
        switch (Types[i])
        {
        case Double:
            Array[i].number = (rand() % 100) * 1.1; //можно вводить с клавиатуры
            break;
        case Int:
            Array[i].digit = rand() % 100; //можно вводить с клавиатуры
            break;
        case Char:
            Array[i].symbol = rand() % 256; //можно вводить с клавиатуры
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        switch (Types[i])
        {
        case Double:
            cout << Array[i].number << " ";
            break;
        case Int:
            cout << Array[i].digit << " ";
            break;
        case Char:
            cout << Array[i].symbol << " ";
            break;
        }
    }
    cout << endl;
    cout << "Размер массива объектов типа данных Store: " << sizeof(Array) << endl;

    Store DOUBLE_NUMBER{};
    DOUBLE_NUMBER.number = 3.14;
    cout << "Вещественное число" << DOUBLE_NUMBER.number << endl;

    Store INT_DIGIT{};
    INT_DIGIT.digit = 15;
    cout << "Целое число: " << INT_DIGIT.digit << endl;

}


