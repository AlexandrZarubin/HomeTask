// TemplateLineSearch
#include <iostream>
#include <stdlib.h>
//#include <cstdlib>
#include <time.h>

using namespace std;
//прототип шаблона функции Линейный поиск
template <typename T, typename L> L LineSearch(T Array[], L Size, T Key);
//template <typename T, typename L> L LineSearch(T [], L , T );

int main()
{
    system("chcp 1251");
    system("cls");
    srand(time(NULL));
    //size_t Size=100; //это раскроется в unsigned int Size=100;
    const unsigned short Size = 100;
    unsigned short Element_Index = 0;
    int ArrayInt[Size]{}, IntKey = 0; //массив и переменная для поиска значения
    float ArrayFloat[Size]{}, FloatKey = 0;
    char ArrayChar[Size]{}, CharKey = 0;
    for (unsigned short i = 0; i < Size; i++) //for(int i = 0; i < Size; i++)
    {
        ArrayInt[i] = rand() % (100 - (-99)) - 99;
        ArrayFloat[i] = (rand() % (100 - (-99)) - 99) * 1.001F;
        ArrayChar[i] = rand() % 256;
        cout << "[" << i << "]\t" << ArrayInt[i] << "\t" << ArrayFloat[i] << "\t" << ArrayChar[i] << endl;
    }
    //ввод данных для поиска
    cout << "\nВведите значение искомого элемента типа данных int: "; cin >> IntKey;
    cout << "\nВведите значение искомого элемента типа данных float: "; cin >> FloatKey;
    cout << "\nВведите значение искомого элемента типа данных char: "; cin >> CharKey;
    //поиск целого числа
    Element_Index = LineSearch(ArrayInt, Size, IntKey);
    if (Element_Index == Size)cout << "Искомый элемент не найден!" << endl;
    //if(Element_Index==-1)cout<<"Искомый элемент не найден!"<<endl;
    else cout << "Индекс искомого элемента типа данных int равен: " << Element_Index << endl;
    //поиск вещественного числа
    Element_Index = LineSearch(ArrayFloat, Size, FloatKey);
    if (Element_Index == Size)cout << "Искомый элемент не найден!" << endl;
    else cout << "Индекс искомого элемента типа данных float равен: " << Element_Index << endl;
    //поиск символа
    Element_Index = LineSearch(ArrayChar, Size, CharKey);
    if (Element_Index == Size)cout << "Искомый элемент не найден!" << endl;
    else cout << "Индекс искомого элемента типа данных char равен: " << Element_Index << endl;
}
//реализация шаблона функции Линейный поиск
template<typename T, typename L> L LineSearch(T Array[], L Size, T Key)
{
    for (L i = 0; i < Size; i++)//тип данных счетчика должен совпадать (или быть не меньше) типа данных массива
    {
        if (Array[i] == Key)return i; //возвращаем индекс найденного элемента
    }
    //если элемент не найден
    //return -1; //возрат в функция, с размером массива знакового типа данных(int, short, long long ...)
    return Size; //возврат размера массива для беззнаковых типов данных размера Size(unsigned int, unsigned short)
}
