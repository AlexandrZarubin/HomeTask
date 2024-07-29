// Reference
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


//прототип функции меняющей значения двух переменных местами
//void Change(int A, int B);
void Change(int, int); //в прототипе можно не указывать имена параметров, но типы данных обязательно

//прототип функции меняющей значения двух переменных местами, принемает адреса переменных при вызове
//void Change_Pointers(int* pA, int* pB);
void Change_Pointers(int*, int*); //в прототипе можно не указывать имена параметров, но типы данных обязательно

//прототип функции меняющей значения двух переменных местами, использует ссылке в качестве аргументов
//void Change_Refence(int& refA, int& refB);
void Change_Refence(int&, int&);

//Функция поиска максимального значения элемента массива, возвращает ЗНАЧЕНИЕ
int Max_Element(int Array[], int Size)
{
    int index_max_element = 0; //индекс максимального элемента
    for (int i = 1; i < Size; i++)
    {
        //находим индекс максимального элемента
        index_max_element = (Array[i] > Array[index_max_element]) ? i : index_max_element;
    }
    cout << "\nМаксимальный элемент A[" << index_max_element << "]=" << Array[index_max_element] << endl;
    return Array[index_max_element]; //возвращает ЗНАЧЕНИЕ максимального элемента
}
//Функция поиска максимального значения элемента массива, возвращает АДРЕС(указатель)
int* Ptr_Max_Element(int Array[], int Size)
{
    int index_max_element = 0; //индекс максимального элемента
    for (int i = 1; i < Size; i++)
    {
        //находим индекс максимального элемента
        index_max_element = (Array[i] > Array[index_max_element]) ? i : index_max_element;
    }
    cout << "\nМаксимальный элемент A[" << index_max_element << "]=" << Array[index_max_element] << endl;
    //return &Array[index_max_element]; //возвращает АДРЕС максимального элемента с помощью индексирования и взятия адреса
    return Array + index_max_element; //возвращает АДРЕС максимального элемента с помощью смещения адреса из укзателя от начала массива на нужный элемент
}
//Функция поиска максимального значения элемента массива, возвращает ССЫЛКУ
int& Ref_Max_Element(int Array[], int Size)
{
    int index_max_element = 0; //индекс максимального элемента
    for (int i = 1; i < Size; i++)
    {
        //находим индекс максимального элемента
        index_max_element = (Array[i] > Array[index_max_element]) ? i : index_max_element;
    }
    cout << "\nМаксимальный элемент A[" << index_max_element << "]=" << Array[index_max_element] << endl;
    return Array[index_max_element]; //возвращает ССЫЛКУ максимального элемента
}


int main()
{
    system("chcp 1251");
    system("cls");
    srand(time(NULL));
    /*
    int X = 15;
    //ссылка на переменную Х(ссылка на значение переменной Х)
    int& ref_X=X;
    cout << "X= " << X << endl;
    cout << "ref_X= " << ref_X << endl;
    ref_X += 15; //все действия над ссылкой выполняются над самой переменной Х
    cout << "X= " << X << endl;
    cout << "ref_X= " << ref_X << endl;
    int Y = 17;
    ref_X = Y; //присваивание значения переменной Y в переменную X по ссылке на неё ref_X
    cout << "X= " << X << endl;
    cout << "ref_X= " << ref_X << endl;
    int& ref_Y = Y;
    ref_Y = 100;
    cout << "Y= " << Y << endl;
    ref_X = ref_Y; //присваивание значения переменной Y, взятого по ссылке ref_Y
    //в переменную X по ссылке на неё ref_X
    cout << "X= " << X << endl;
    cout << "Адрес переменной Х: " << &X << endl;
    cout << "Адрес переменной Х, взятый по ссылке: " << &ref_X << endl;
    system("cls");

    float* ptr = nullptr; //нулевой указатель, созданный до объекта
    //блок кода - ограничивает область видимость
    {
        float PI = 3.14F; //локальная переменная блока
        float& ref_PI = PI; //ссылка на локлаьную переменну блока кода
        float* ptr_PI = &PI; //указатель на локальную переменную блока кода
        cout << "Значение PI по имени:     " << PI << endl;
        cout << "Значение PI по ссылке:    " << ref_PI << endl;
        cout << "Значение PI по указателю: " << *ptr_PI << endl;
        ptr = &PI; //"нацелим" внешний указатель на локальную переменную PI блока кода
        cout << "Значение PI по указателю ptr: " << *ptr << endl;
        cout << "Адрес PI по указателю ptr: " << ptr << endl;
    }
    //все локальные объекты блока кода перестали быть доступны
    cout << "Конец блока кода!" << endl;
    //cout << "Значение PI по имени:     " << PI << endl;
    //cout << "Значение PI по ссылке:    " << ref_PI << endl;
    //cout << "Значение PI по указателю: " << *ptr_PI << endl;
    cout << "Значение PI по указателю ptr: " << *ptr << endl;
    cout << "Адрес PI по указателю ptr: " << ptr << endl;
    ptr = nullptr; //после уничтожения объекта, на который указывал укзаатель, указатель нужно или "перенацелить" или обнулить
    */

    /*
    int One = 15, Two = -3;
    cout<<"Число One: "<<One<<" Число Two: "<<Two<<endl;
    Change(One, Two); //в функцию при вызове передаются только значения(содержимое), а не сами переменные
    cout<<"Число One: "<<One<<" Число Two: "<<Two<<endl;
    cout <<"\n"<< endl;
    Change_Pointers(&One, &Two); //при вызове функции передаем в неё адреса переменных, полученные через операцию взятие адреса
    cout << "Число One: " << One << " Число Two: " << Two << endl;
    int *pOne = &One, *pTwo = &Two; //объявление и инициализация двух указателей
    Change_Pointers(pOne, pTwo); //при вызове функции передаем в неё адреса переменных, полученные как содержимое укзаателей pOne и pTwo
    cout << "Число One: " << One << " Число Two: " << Two << endl;
    cout << "\n" << endl;

    Change_Refence(One, Two);  //при вызове функции будут созданы ссылки на переменные, чьи имена указаны при вызове
    cout << "Число One: " << One << " Число Two: " << Two << endl;
    int& rOne=One, & rTwo=Two;
    Change_Refence(rOne, rTwo); //при вызове функции будут созданы копии ссылок на переменные.
    cout << "Число One: " << One << " Число Two: " << Two << endl;
    */

    const int Size = 10;
    int A[Size]{};
    for (int i = 0; i < Size; i++)
    {
        A[i] = rand() % (100 - (-99)) - 99;
        cout << A[i] << " ";
    }
    cout << endl;
    int Max = 0;
    Max = Max_Element(A, Size); //присваиваем результат работы функции в переменную Max
    cout << "Значение максимального элемента массива: " << Max_Element(A, Size) << endl;
    cout << "Значение максимального элемента массива: " << Max << endl;

    //Max_Element(A, Size) = 100;// Так нельзя

    Max = *Ptr_Max_Element(A, Size); //присваиваем результат работы функции в переменную Max, разыменовав указатель
    cout << "Значение максимального элемента массива: " << *Ptr_Max_Element(A, Size) << endl;
    cout << "Значение максимального элемента массива: " << Max << endl;

    //*Ptr_Max_Element(A, Size) = 555; //заменяем значение максимального элемента массива, 
    //помещаем по адресу(результату работы функции) новое значение, разыменовав указаетель

    Max = Ref_Max_Element(A, Size); //присваиваем результат работы функции в переменную Max
    cout << "Значение максимального элемента массива: " << Ref_Max_Element(A, Size) << endl;
    cout << "Значение максимального элемента массива: " << Max << endl;

    Ref_Max_Element(A, Size) = 777; //заменяем значение максимального элемента массива,
    //помещаем по ссылке(результату работы функции) новое значение

    for (int i = 0; i < Size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
//реализация функции меняющей значения двух переменных местами
void Change(int A, int B)  //копирование значений в собственные переменные А и В(параметры функции)
{ //int A=One, B=Two; //функция работает только с копиями значений
    cout << "Работает функция Change!" << endl;
    cout << "Первое число: " << A << " Второе число: " << B << endl;
    int temp = A;
    A = B;
    B = temp;
    cout << "Первое число: " << A << " Второе число: " << B << endl;
    cout << "Функция Change завершила работу!" << endl;
}
//реализация функции меняющей значения двух переменных местами, принемает адреса переменных при вызове
void Change_Pointers(int* pA, int* pB)
{
    //int* pA=&One;
    //int* pB=&Two;
    //int* pA=pOne;
    //int* pB=pTwo;
    int temp = *pA;
    *pA = *pB;
    *pB = temp;
}
//реализация функции функции меняющей значения двух переменных местами, использует ссылке в качестве аргументов
void Change_Refence(int& refA, int& refB)
{
    //int& refA=One;
    //int& refB=Two;
    int temp = refA;
    refA = refB;
    refB = temp;
}
