// Pointers_And_Arrays
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <ctime>

using namespace std;

//void Randomize(int ptr[], int Size)
void Randomize(int* ptr, int Size)
{
    //int* ptr=Array; //указатель ptr получает адрес переданного в функцию массива
    //int Size=5;

    //I вариант
    /*for (int i = 0; i < Size; i++)
    {
        ptr[i] = rand() % (100 - (-99)) - 99;
        cout<<"Array["<<i<<"]="<<ptr[i]<<" ";
    }
    cout << endl;*/
    //II вариант
    /*for (int i = 0; i < Size; i++)
    {
        *(ptr+i) = rand() % (100 - (-99)) - 99;
        cout << "Array[" << i << "]=" << *(ptr+i) << " ";
    }
    cout << endl;*/
    //III вариант
    for (int i = 0; i < Size; i++, ptr++) //ptr++ сдивигаем указатель к следующему элементу
    {
        *ptr = rand() % (100 - (-99)) - 99;
        cout << "Array[" << i << "]=" << *ptr << " ";
    }
    cout << endl;
}

int main()
{
    system("chcp 1251");
    system("cls");
    srand(time(NULL)); //srand(time(nullptr));
    int A = 15;
    int Array[5]{ 1,2,3,4,5 };
    int* ptrA = &A;
    //Получения адреса массива
    cout << "Адрес начала массива в памяти: " << &Array << endl;
    cout << endl;
    cout << Array << endl;
    //Array - указатель, хранящий адрес начала последовательности из 5ти элементов типа данных int
    cout << endl;
    cout << &Array[0] << endl; //взятие адреса нулевого элемента массива
    cout << &Array[1] << endl;
    cout << &Array[2] << endl; //взятие адреса второго элемента массива
    cout << &Array[3] << endl;
    cout << &Array[4] << endl;
    cout << endl;
    cout << Array + 0 << endl;    //cout << Array << endl;
    cout << Array + 1 << endl;
    cout << Array + 2 << endl;    //увеличиваем адрес из указателя Array на 2*int(2*4байта)
    cout << Array + 3 << endl;
    cout << Array + 4 << endl;
    cout << endl;

    //cout << Array[10] << endl; //выход за границы массива
    //cout << Array[-2] << endl; //выход за границы массива
    //cout << Array + 10 << endl;  //выход за границы массива
    //cout << Array -2 << endl;  //выход за границы массива
    //cout << &Array[10] << endl; //выход за границы массива
    //cout << &Array[-2] << endl; //выход за границы массива

    //значение элементов массива, через разыменование и сдвиг указателя
    cout << *(Array + 0) << endl;    //cout << *Array << endl; //значение нулевого элемента массива
    cout << *(Array + 1) << endl;
    cout << *(Array + 2) << endl;    //cout<<Array[2]<<endl; //значение элемента массива с индексом 2
    cout << *(Array + 3) << endl;
    cout << *(Array + 4) << endl;


    cout << &Array[4] << endl; //1 &(*(Array + 4))
    cout << Array + 4 << endl;   //2 Array + 4

    //нельзя изменить сожержимое имени массива, Array всегда будет указывать на начало массива
    //Array++;
    //Array += 3; //Array = Array+ 3;
    //Array = &A;

    //объявление нулевого указателя
    int* PTR = 0; //можно, но корректно
    int* PTR1 = NULL; //можно, синтаксис языка C
    int* PTR2 = nullptr; //нужно, синтаксис языка C++

    cout << PTR2 << endl;
    //cout << *PTR2 << endl; //нельзя разыменовывать нулевой указатель
    if (PTR1 != nullptr)cout << *PTR1 << endl; //если указатель не нулевой
    if (PTR2)cout << *PTR2 << endl;  //если указатель существует(если указатель не нулевой)
    if (!PTR)cout << "Указатель нулевой!" << endl;

    //PTR = &Array; //взяитие адреса массива целиком
    PTR = Array; //в указатель PTR помещаем адрес начала массива, хранящийся в Array
    PTR++; //теперь указатель PTR хранит адрес элемента массива с индексом 1
    cout << *PTR << endl;
    PTR = &Array[2];
    cout << *PTR << endl;
    PTR = Array + 4;
    cout << *PTR << endl;


    Randomize(Array, 5);
    //передавая в функцию имя массива, мы передаем значение указателя Array
    //(адрес начала массива из 5 элементов типа данных int)
}
