// TemplateFunction
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
//шаблон функции поиска максимального элемента массива для массивов различных типов данных
template <typename T> T Find_Max_Element(T Array[], int Size)
//например           int Find_Max_Element(int Array[], int Size)
{
    T Max_Element = Array[0]; //переменная Max_Element будет иметь тот же тип данных, что и элементы массива Array
    for (int i = 1; i < Size; i++)
    {
        Max_Element = Array[i] > Max_Element ? Array[i] : Max_Element;
        //if(Array[i]>Max_Element)Max_Element=Array[i]; else Max_Element=Max_Element;
    }
    return Max_Element;
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
    float D[Size]{};
    for (int i = 0; i < Size; i++)
    {
        A[i] = rand() % (100 - (-99)) - 99;
        B[i] = (rand() % (100 - (-99)) - 99) * 1.001;
        C[i] = rand() % 256;
        D[i] = (rand() % (100 - (-99)) - 99) * 1.001F;
        cout << A[i] << "\t" << B[i] << "\t" << C[i] << endl;
    }
    cout << "Максимальный элемент для типа данных int: " << Find_Max_Element(A, Size) << endl;
    cout << "Максимальный элемент для типа данных int: " << Find_Max_Element(B, Size) << endl;
    cout << "Максимальный элемент для типа данных int: " << Find_Max_Element(C, Size) << endl;
    cout << "Максимальный элемент для типа данных int: " << Find_Max_Element(D, Size) << endl;
    //cout << "Максимальный элемент для типа данных int: " << Find_Max_Element(Size, D) << endl;//такой реализций нет
}
