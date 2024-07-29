// CodePages

#include <iostream>
#include<locale.h>
#include<stdlib.h>
#include <windows.h> // содержит функии от ОС Windows
using namespace std;
int main()
{
    //setlocale(LC_ALL, "rus"); // в среде windwos только на вывод текста



    // с помощью команды самой консоли, передаваемых черех system

    //system("chcp"); //вывод текующей кодировки на экран консоли

    //   1 вариант как пользователи 
    //system("chcp 1251");// установка кодовой страницы 1251 для консоли целиком
    //system("cls");//очистка экрана после смены кодовой страницы

    //   2 вариант как создатели

    // команды языка С из библиотеки windwos
    //узнать текущие кодовые страницы в консоли
    int CP = GetConsoleCP();
    int OCP = GetConsoleOutputCP();
    //если текущие кодировки не подходят, меняем на нужные
    if (OCP != 1251)SetConsoleOutputCP(1251);  //установка кодировки на вывод текста
    if (CP != 1251)SetConsoleCP(1251);        //Установка общей кодировки(Ввод текста)

    cout << "Привет, мир!" << endl;
    char Symbol;//0...127 //0...255 //-128...127
    //unsigned char Symbol;
    cout << "Введите символ: "; cin >> Symbol;
    if (Symbol == 'Щ') cout << "это буква Щ!" << endl;
    else cout << "It's not SCH" << endl;
    cout << "символ: " << Symbol << endl;

    //Если кодировки менялись, нужно вернуть прежнею
    if (OCP != 1251)SetConsoleOutputCP(OCP);
    if (CP != 1251)SetConsoleCP(CP);
}

