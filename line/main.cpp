// line

#include <iostream>
#include<locale.h>
#include<stdlib.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "---Программа выводит на экран линию из символов!---" << endl;
    int count = 0, i = 0;
    char  symbol = ' ';
    //цикл повторной работы программы
    while (symbol != '0')
    {
        cout << "Введите символ: "; cin >> symbol;
        //цикл проверки ввода кол-ва символов
        do
        {
            cout << "Введите кол-во сиволовв линий больше нуля: "; cin >> count;
            if (count <= 0)cout << "Кол-во символов должно быть больше нуля! Повторите ввод!" << endl;
        } while (count <= 0);
        //цикл вывода сиволов
        while (i < count)
        {
            cout << symbol;
            i++;
        }
        cout << endl;
        //Вопрос о продолжений
        cout << "Для выхода введите 0, для продолжения введите любой сивол!" << endl;
        cin >> symbol;
        i = 0;//обнуления счетчика
        system("cls");
    }

}

