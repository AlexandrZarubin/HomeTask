﻿// ConstField
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
//класс с константами в полях
class ConstField
{
public:
    //собственные(нестатические) поля
    string STR = "Привет, Мир!"; //собственное поле со значением по умолчанию, 
    //вызывается конструктор с параметрами
    const double PI = 3.14;    //собственная константа для каждого объекта,
    //const double PI{3.14}; //её начально значение указано и может быть изменено только в конструкторе,
    //и только с помощью унифицированной инициализации и больше никак

    const int ID; //собственная константа для каждого объекта класса, её занчение
    //в классе не указано, а обязательно задается при создании каждого объекта

    const string Name; //константа типа данных string с пустой строкой внутри
    //будет вызван по умолчанию(без парамтеров)


    //только с помощью унифицированной инициализации полей можно инициализировать или изменить значение константного поля
    ConstField() : ID{ 10 }, PI{ 3.141592 } {}

    //конструктор с параметрами и унифицированной инициализацией полей
    ConstField(int id, string name) : ID{ id }, Name{ name } {}

    /*void SetID(int id)
    {
        ID = id;
    }*/
};

int main()
{
    system("chcp 1251");
    system("cls");

    ConstField A; //конструктор по умолчанию не заполнит константу Name
    cout << A.Name << ": " << A.STR << " " << A.PI << " " << A.ID << endl;
    //A.PI = 4; //нельзя изменить константу после инициализации
    //A.ID = 4; //нельзя изменить константу после инициализации

    A.STR = "Ура Воскресенье!";
    cout << A.Name << ": " << A.STR << " " << A.PI << " " << A.ID << endl;

    ConstField B; //конструктор по умолчанию не заполнит константу Name
    cout << B.Name << ": " << B.STR << " " << B.PI << " " << B.ID << endl;

    ConstField C{ 100, "Объект C" }; //конструктор с параметром изменит содержимое константы ID и константы Name, а PI возмент по умолчанию
    cout << C.Name << ": " << C.STR << " " << C.PI << " " << C.ID << endl;

    //константные поля после создания объекта нельзя изменить
    //С.PI = 4;
    //С.ID = 4;
    //C.Name = "УРА!";
    //некоснтантное поле можно изменить после создания объекта
    C.STR = "Ура!";

    ConstField D{ 101, "Объект D" }; //конструктор с параметром изменит содержимое константы ID и константы Name, а PI возмент по умолчанию
    cout << D.Name << ": " << D.STR << " " << D.PI << " " << D.ID << endl;

    system("cls");

    string Buffer; //временная строка для ввода
    int ID = 0;

    cout << "Введите название объекта: ";
    //cin >> Buffer; //считает строку до пробела
    getline(cin, Buffer); //функци ввода строки string с пробелами
    cout << "Введите ID объекта: ";
    cin >> ID;

    ConstField E{ ID,Buffer };
    cout << E.Name << ": " << E.STR << " " << E.PI << " " << E.ID << endl;
    //константные поля после создания объекта нельзя изменить
    //E.PI = 4;
    //E.ID = 4;
    //E.Name = "УРА!";
    //некоснтантное поле можно изменить после создания объекта
    E.STR = "Ура!";
    cout << E.Name << ": " << E.STR << " " << E.PI << " " << E.ID << endl;



}
