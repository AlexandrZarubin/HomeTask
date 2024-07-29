// Arguments
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
//int main(char* Spisok[], int Size)
{
    //argc - кол-во аргументов, переданных в программу при запуске
    //argv - массив строк(указателей char*) - массив аргументов

    system("chcp 1251");
    system("cls");

    /*cout << "Кол-во аргументов: " << argc << endl;
    cout << "Значение аргумента: " << argv[0] << endl;*/

    string STR;

    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "/help"))cout << "Справке о программе char[]!" << endl;
        STR = argv[i];
        if (STR == "/?")cout << "Справке о программе string!" << endl;
        if (STR == "-t")cout << "Введен ключ -t: Запускаю режим самоуничтожения!" << endl;
        if (STR == "Привет, Мир!")cout << STR << endl;
    }

    //strcpy_s(argv[0], 11 , "D:\\ARG.exe");
    //cout << "Значение аргумента: " << argv[0] << endl;


    system("pause");
    //return 555;
}
