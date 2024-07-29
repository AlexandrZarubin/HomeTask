// OverLoadFunctions
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
//перегрузка функции по типу данных аргументов
int Find_Max_Element(int Array[], int Size) //для типа данных int
{
    int Max_Element = Array[0];
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i]>Max_Element)Max_Element=Array[i]; else Max_Element=Max_Element;
    }
    cout << "Для типа данных int: ";
    return Max_Element;
}
//типы данных возвращаемого значения в перегруженных функция могут совпадать
double Find_Max_Element(double Array[], int Size) //для типа данных double
{
    double Max_Element = Array[0];
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i]>Max_Element)Max_Element=Array[i]; else Max_Element=Max_Element;
    }
    cout << "Для типа данных double: ";
    return Max_Element;
}
char Find_Max_Element(char Array[], int Size) //для типа данных char
{
    char Max_Element = Array[0];
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i]>Max_Element)Max_Element=Array[i]; else Max_Element=Max_Element;
    }
    cout << "Для типа данных char: ";
    return Max_Element;
}
//эта функция отличается от double Find_Max_Element(double Array[], int Size) порядком аргументов и является самостоятельной перегрузкой
double Find_Max_Element(int Size, double Array[]) //для типа данных double
{
    double Max_Element = Array[0];
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i]>Max_Element)Max_Element=Array[i]; else Max_Element=Max_Element;
    }
    cout << "Для типа данных double: ";
    return Max_Element;
}
//перегрузка функции по количеству аргументов
double Multy(double X = 3.5) //1 аргумент
{
    return X * X;
}
double Multy(double X, double Y) //2 аргумента
{
    return X * Y;
}
double Multy(double X, double Y, double Z) //3 аргумента
{
    return X * Y * Z;
}
double Multy(double X, double Y, double Z, double W) //4 аргумента
//double Multy(double X, double Y, double Z, double W = 3.5) //перегрузка функции с 4мя параметрами,
//1 из которых исеет значение по умолчанию. Такая ситуация будет неоднозначной, так как
//компилятор не будет знать какую из перегруженных функций вызвать
{
    return X * Y * Z * W;
}

int main()
{
    system("chcp 1251");
    system("cls");
    srand(time(NULL));
    const int Size = 10;
    int A[Size]{};
    double B[Size]{};
    char C[Size]{};
    for (int i = 0; i < Size; i++)
    {
        A[i] = rand() % (100 - (-99)) - 99;
        B[i] = (rand() % (100 - (-99)) - 99) * 1.001;
        C[i] = rand() % 256;
        cout << A[i] << "\t" << B[i] << "\t" << C[i] << endl;
    }
    cout << Find_Max_Element(A, Size) << endl;
    cout << Find_Max_Element(B, Size) << endl;
    cout << Find_Max_Element(C, Size) << endl;
    cout << Find_Max_Element(Size, B) << endl;
    //cout << Find_Max_Element(Size, A) << endl; //такой перегрузки нет, нужна отдельная реализация перегрузки
    system("cls");
    cout << Multy() << endl;
    cout << Multy(3.14) << endl;
    cout << Multy(3.14, 2.5) << endl;
    cout << Multy(3.14, 2.5, 0.4) << endl;
    cout << Multy(3.14, 2.5, 0.4, 0.2) << endl;
    //cout << Multy(3.14, 2.5, 0.4, 0.2, 3.7) << endl; //такой перегрузки нет, нужна отдельная реализация перегрузки
}
