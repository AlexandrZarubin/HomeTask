// System
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    /*system("help");
    system("cls");
    system("dir");
    system("cls");
    system("dir C:\\Windows");
    system("cls");
    system("chcp 1251");
    system("ping 8.8.8.8 -t");*/

    char Command[255]{};
    do
    {
        system("chcp 1251");
        system("cls");
        cout << "Введите команду, как в командной строке cmd: ";
        gets_s(Command);
        system("chcp 866");
        system("cls");
        system(Command);
        cout << endl;
        system("pause");
    } while (_stricmp(Command, "exit"));
    //system("pause");
}
