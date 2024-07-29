﻿#pragma once //директива препроцессора исключает множественное подключение файла
#include <iostream> //вывод на экран
#include <windows.h>  //кодировка

using namespace std;

//определение структуры, содержащей дату

struct Date //Date - имя нового типа данных
{
	//поля структуры
	unsigned short Day; //День
	char Month[12];     //Месяц
	int Year;			//Год
};

//функция вывода даты на экран
void Show(Date D)
{
	//получение значения текущей кодировки консоли на вывод текста
	int OCP = GetConsoleOutputCP();
	//если текущая кодировка не подходит, изменяем на нужную
	if (OCP != 1251)SetConsoleOutputCP(1251);

	//оператор . -оператор доступа к полям структуры по имени объекта
	cout << D.Day << "." << D.Month << "." << D.Year << endl;

	//если кодировка менялась, возвращаем прежнюю кодировку
	if (OCP != 1251)SetConsoleOutputCP(OCP);
}

//функция ввода даты с клавиатуры, возвращает объект(экземпляр) типа данных Date
Date Input()
{
	//получение значения текущих кодировки консоли на вывод и ввод текста
	int OCP = GetConsoleOutputCP();
	int CP = GetConsoleCP();
	//если текущая кодировки не подходят, изменяем на нужные
	if (OCP != 1251)SetConsoleOutputCP(1251);
	if (CP != 1251)SetConsoleCP(1251);

	Date Temp{}; //объявление пустого(нулевого) объекта структуры Date

	cout << "Введите дату через Пробелы или Enter: " << endl;
	cin >> Temp.Day >> Temp.Month >> Temp.Year;

	//если кодировки менялись, возвращаем прежние кодировки
	if (OCP != 1251)SetConsoleOutputCP(OCP);
	if (CP != 1251)SetConsoleCP(CP);

	return Temp; //возвращаем объект в результате работы функции
}
//перегрузка функции ввода даты с клавиатуры, использует указатель на тип данных Date в качестве параметра и применает адрес объекта, 
// который нужно заполнить
void Input(Date* PTR)
{
	// получение значения текущих кодировки консоли на вывод и ввод текста
	int OCP = GetConsoleOutputCP();
	int CP = GetConsoleCP();
	//если текущая кодировки не подходят, изменяем на нужные
	if (OCP != 1251)SetConsoleOutputCP(1251);
	if (CP != 1251)SetConsoleCP(1251);

	cout << "Введите день: "; cin >> PTR->Day; //PTR->Day обращение к полю Day через указатель PTR на тип данных Date
	cout << "Введите месяц: "; cin >> PTR->Month; //-> оператор доступа к полям структуры по указателю на объект (селектор)
	cout << "Введите год: "; cin >> PTR->Year;

	//если кодировки менялись, возвращаем прежние кодировки
	if (OCP != 1251)SetConsoleOutputCP(OCP);
	if (CP != 1251)SetConsoleCP(CP);

}

//перегрузка функции ввода даты с клавиатуры, использует ссылку на тип данных Date в качестве параметра

void Input(Date& REF)
{
	//получение значения текущих кодировки консоли на вывод и ввод текста
	int OCP = GetConsoleOutputCP();
	int CP = GetConsoleCP();
	//если текущая кодировки не подходят, изменяем на нужные
	if (OCP != 1251)SetConsoleOutputCP(1251);
	if (CP != 1251)SetConsoleCP(1251);
	//обращение к полю по ссылке на объект типа данных Date чреез опереатор . так же как и по имени объекта
	cout << "Введите день: "; cin >> REF.Day;
	cout << "Введите месяц: "; cin >> REF.Month;
	cout << "Введите год: "; cin >> REF.Year;

	//если кодировки менялись, возвращаем прежние кодировки
	if (OCP != 1251)SetConsoleOutputCP(OCP);
	if (CP != 1251)SetConsoleCP(CP);
}


