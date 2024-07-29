// Struct1

//#include <iostream> //можно не подключать, так как её подключит Date.h
#include <stdlib.h>
#include <string.h>
#include "Data.h" //подключение собсвтенного заголовочного файла(файл в том же каталоге, что и проект)
//#include "C:\YandexDisk\WorksStudy\lesson\Struct1\Date1.h" //подключение собсвтенного заголовочного файла(по полному пути)
//#include "D:\Headers\Date.h" //подключение собсвтенного заголовочного файла(по полному пути)
//using namespace std; //можно не подключать, так как её подключит Date.h


Date Birthday; //глобальный объект структуры Date, автоматически инициализируется нулями


int main()
{

    system("chcp 1251");
    system("cls");

    /*//создаем объект типа данных Date(экземпляр структуры Date)
    //переменню типа данных Date
    Date Today{ 30,"апреля",2023 }; //унифицированная инициализация
    //cout << Today << endl; //так не сработает
    cout << Today.Day << "." << Today.Month << "." << Today.Year << endl;
    Show(Today); //передача объекта структуры Date в функцию
    Today.Day = 31; //Today.Day - доступ к полю структуры по имени
    Show(Today); //передача объекта структуры Date в функцию
    Show(Birthday);
    system("cls");

    Birthday = Input(); //вызов функции, вовзращающей результат типа данных Date
    Show(Birthday);

    Today = Birthday;
    Show(Today);
    */


    //динамический массив объектов типа данных Date
    int Size = 0;
    cout << "Введите кол-во дат: "; cin >> Size;
    Date* History_Dates = new Date[Size]{};



    for (int i = 0; i < Size; i++)
    {
        cout << "Введите " << i + 1 << "-ю дату: " << endl;
        //I Вариант через функцию возращающую объект
        //History_Dates[i] = Input(); 
        //II Вариант через функцию принемающую адрес
        //Input(&History_Dates[i]); //через взятие адреса
        //Input(History_Dates + i); //через смещение указателя от начла массива
        //III Вариант через функцию использующую ссылку в качетсве аргумента
        //Input(History_Dates[i]);
    }
    system("cls");

    //поиск дат в массиве по году в 20м веке
    int Count = 0;
    for (int i = 0; i < Size; i++)
    {
        if (History_Dates[i].Year >= 1901 && History_Dates[i].Year <= 2000)   //если поле Year i-го элемента массива с 1901 по 2000
        {
            Count++;
            Show(History_Dates[i]);
        }
    }
    cout << "Кол-во дат 20го века: " << Count << endl;
    //совобождение памяти
    delete[] History_Dates;
    History_Dates = nullptr;

    //условие совпадения дня и месяца сегодя-ня с днем рождения
    //if(Today.Day == Birthday.Day && !strcmp(Today.Month,Birthday.Month)) 
    //cout<<"С днем рождения!"<<endl;

}

