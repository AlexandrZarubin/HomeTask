﻿// ReSize
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
//прототип шаблона функции изменения размера массива, возращает адрес нового массива
//template<typename T, typename L> T* ReSize(T* Array, L& Size, L NewSize = 0);
template<typename T, typename L> T* ReSize(T*, L&, L = 0);

int main()
{
    system("chcp 1251");
    system("cls");
    srand(time(NULL));
    int Size = 0;
    int* A = nullptr; //нулевой укзаатель, который позже будет хранить адрес динамически выделенной памяти
    //под набор элемент кол-во Size
    cout << "Введите размер массива: "; cin >> Size; //Проверка ввода!
    A = new int[Size] {}; //new сработает с любым типом данных
    if (!A) { cout << "Ошибка выделения памяти!" << endl; exit(1); }
    for (int i = 0; i < Size; i++)
    {
        A[i] = rand() % (100 - (-99)) - 99;
        cout << "A[" << i << "]=" << A[i] << " ";
    }
    cout << endl;
    //вызов функции, присвоит в указатель А адрес новой памяти(нового массива) с нужным кол-вом элементов
    A = ReSize(A, Size); //новый размер вводится с клавиатуры внутри функции
    //A = ReSize(A, Size,10); //явно передается новый размер и массив станет размером в 10 элементов
    //вывод итогово массива
    for (int i = 0; i < Size; i++)
    {
        cout << "A[" << i << "]=" << A[i] << " ";
    }
    cout << endl;
    //освобождение памяти
    if (A) { delete[] A; A = nullptr; }
    else cout << "Память уже была освобождена!" << endl;
}
//реализация шаблона функции изменения размера массива, возращает адрес нового массива
template<typename T, typename L> T* ReSize(T* Array, L& Size, L NewSize)
{
    while (NewSize <= 0)
    {
        cout << "Введите новый размер массива: ";
        cin >> NewSize;
        if (NewSize <= 0)cout << "Размер массива должен быть больше нуля! Повторите ввод!" << endl;
    }
    if (Size == NewSize)return Array; //если размеры равны вернем адрес старого массива
    T* Result = nullptr; //указатель, хранит адрес новой памяти, выделенной под массив нужного размера
    Result = new T[NewSize]{}; //выделение памяти нужного размера и заполнение её нулями нужного типа данных T
    if (!Result)
    {
        //Вариант 1 завершение работы всей программы, необходимо освободить всю ранее выделенную память
        cout << "Ошибка выделения памяти!" << endl;
        if (Array) { delete[] Array; Array = nullptr; }
        else cout << "Память уже была освобождена!" << endl;
        exit(1);
        //Вариант 2 выход из функции с вовзвратом старого массива
        cout << "Не удалось выделить память, массив не будет изменен!" << endl;
        return Array;
    }
    for (L i = 0; i < NewSize; i++)
    {
        if (i < Size)Result[i] = Array[i]; //копируем элементы из старого массива в новый
        else break; //если элементов в старом массиве не осталось, выход, так новый массив был заполнен нулями при создании
    }
    //освобождаем память, выделенную под старый массив
    if (Array) { delete[] Array; Array = nullptr; }
    else cout << "Память уже была освобождена!" << endl;
    Size = NewSize; //изменяем старый размер массива на новый по ссылке
    return Result; //возвращаем адрес новой памяти(нового массива)
}
