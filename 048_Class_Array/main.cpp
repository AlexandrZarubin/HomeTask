// ClassArray
#include <iostream>
#include "Array.h" //подключение собственного заголовочного файла
#include "C:\YandexDisk\WorksStudy\lesson\ClassArray1\Array.h" //подключение по полному пути

//функция создания и заполнения массива случайными числами
Array CreateArray(int Size)
{
    Array TMP(Size); //создает временный объект указанного размера
    TMP.Randomize(-99, 99); //заполняет объект случайными числами от -99 до 99 включительно
    return TMP; //создается временный безымянный объект, он получает содержимое объекта TMP и возвращается
    //на место вызова функции
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    //обычный объект класса - переменная типа данных Array
    //Array A{ 1,2,3,4,5,6,7,8,9,10 }; //конструктор со списочной инициализацией
    //cout << A << endl;
    //A[3] = 100;
    //cout << A << endl;
    //cout << A[3] << endl;
    //cout << A[128] << endl;

    //константный объект
    //const Array C_A{ 1,2,3,4,5,6,7,8,9,10 };
    //cout << C_A << endl;
    //C_A[3] = 100;
    //cout << C_A[128] << endl; 

    /*
    Array EmptyA; //конструктор по умолчанию
    cout << "Адрес объекта EmptyA: " << &EmptyA << endl;
    EmptyA = CreateArray(10);
    cout<<"Объект EmptyA Заполнен!"<<endl;

    system("cls");
    Array C = EmptyA; //конструктор копирования
    cout <<"EmptyA: "<< EmptyA << endl;
    cout <<"C: "<< C << endl;

    Array B = move(EmptyA); //конструктор перемещения заберет всё содержимое объекта А
    cout << "EmptyA: "<< EmptyA << endl;
    cout <<"B: "<< B << endl;

    EmptyA.ReSize(5);
    for (int i = 0; i < EmptyA.Size(); i++)
    {
        EmptyA[i] = rand() % 100;
        cout << EmptyA[i] << " ";
    }
    cout << endl;

    Array D = EmptyA + B;
    cout << D << endl;

    if (B == C)cout << "Объекты В и С равны!" << endl;
    */

    /*Array E(10);
    cin >> E;
    cout <<"Объект Е: "<< E<<endl;
    E.ReSize(5);
    cout << "Объект Е: " << E << endl;
    E.ReSize(7);
    cout << "Объект Е: " << E << endl;*/

    //массив объектов класса Array (двумерный динамический массив значений типа данных int)
    int Size = 4;
    Array* MASSIVE = new Array[Size]; //конструктор по умолчанию

    for (int i = 0; i < Size; i++)
    {
        //MASSIVE[i] - Объект класса Array
        //I Вариант
        //MASSIVE[i] = CreateArray(10);  
        //cout << MASSIVE[i];
        //operator<<(cout, MASSIVE[i]);
        //II Вариант
        //MASSIVE[i].ReSize(10);
        //MASSIVE[i].Randomize(-99, 99);
        //III Вариант
        MASSIVE[i].ReSize(10);
        for (int j = 0; j < MASSIVE[i].Size(); j++)
        {
            MASSIVE[i][j] = rand() % (100 - (-99)) - 99; //каждый j-й элемент каждого i-го объекта класса Array будет заполнен вручную
        }
    }

    //A + B

    for (int i = 0; i < Size; i++)
    {
        //cout << MASSIVE[i] << endl;
        for (int j = 0; j < MASSIVE[i].Size(); j++)
        {
            cout << MASSIVE[i][j] << "\t";
        }
        cout << endl;
    }
    delete[] MASSIVE; //освобождение памяти выделенной под массив объектов



    Array A(10);
    A.Randomize(-99, 99);
    cout << A << endl;
    //A.Sort(true); //добавить метод сортировки массива
    cout << A << endl;
    A.SortShell(true);
    cout << "сортировка по возрастанию\n" << A << endl;
    A.SortShell(false);
    cout << "сортировка по убыванию\n" << A << endl;

    A -= 2;
    cout << "Array - int \n" << A << endl;

    A /= 2;
    cout << "Array / int \n" << A << endl;

    Array B = A - 2;
    cout << "Array=Array - int \n" << B << endl;

    Array Z = 2 - B;
    cout << "Array= int - Array \n" << Z << endl;
}
