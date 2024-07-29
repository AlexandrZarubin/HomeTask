#pragma once
#include <iostream>
#include <windows.h> //в каждом методе, где есть ввод-вывод символов нужно устанавливать кодировки
#include <stdlib.h>
#include <time.h>
#include <initializer_list> //класс для инициализации путем перечисления значений(унифицированной списочной инициализацией)
#include <assert.h> //макрос assert - выводит на экран системное сообщение об ошибке и прерывает работу программы

using namespace std;

//класс, объекты которого - одномерные динамические массивы элементов типа данных int
class Array
{
	int size = 0;			//кол-во элементов
	int* array = nullptr;	//указатель на элементы типа данных int
public:
	//прототипы методов:
	Array(char) = delete; //отключаем конструктор с char в качестве параметра
	Array() = default; //Array(){} //default - просьба компилятору автоматически сгенерировать и добавить реализацию конструктора по умолчанию(без парамтеров)
	//конструктор с параметром, принемает кол-во элементов
	explicit Array(int);
	//конструктор копирования, lvalue ссылка(ссылка на именованный постоянный объект)
	Array(const Array&);
	//конструктор перемещения служит для извлечения содержимого из одного объекта класса Array в другой при его создании
	Array(Array&&); //rvalue ссылка в качестве аргумента, принемает временные объекты класса Array(как безымянные так и именные)
	//конструктор списочной инициализации A{1,2,3}
	Array(const initializer_list<int>&); //константная ссылка на объект шаблонного класса initializer_list, с типом данных int внутри
	//Деструктор
	~Array();
	//сеттеры:
	//метод заполнения массива случайными числами от указанного числа и до указанного числа включительно
	void Randomize(int, int);
	//метод изменения размера массива
	void ReSize(int);
	//геттеры:
	//метод получения текущего размера массива(кол-ва элементов)
	int Size()const;

	//перегрузка операторов как методов класса
	//перегрузка оператора индексирования []
	int& operator[](int); //как сеттер и геттер для переменных объектов класса Array(для массива переменных типа данных int)
	int operator[](int)const; //как геттер для константных объектов класса Array(для массива констант типа данных int)
	//перегрузка оператора копирующего присваивания =
	Array& operator=(const Array&); //A=B=C;
	//перегрузка оператора перемещающего присваивания = служит для извлченения содержимого из одного объекта класса Array в другой, уже созданный ранее объект 
	Array& operator=(Array&&); //rvalue ссылка в качестве аргумента, принемает временные объекты класса Array(как безымянные так и именные)
	//перегрузка оператора проверки на равенство ==
	bool operator==(const Array&)const; //не может менять содержимое сравниваемых объектов
	//перегрузка оператора проверки на неравенство !=
	bool operator!=(const Array&)const; //не может менять содержимое сравниваемых объектов

	//дружественная перегрузка операторов
	//оператор вывода
	friend ostream& operator<<(ostream&, const Array&); //cout<<"Ура"<<Mass1<<endl;
	//оператор ввода
	friend istream& operator>>(istream&, Array&);

	//--Сортировка шелла
	void SortShell(bool);

	//--Array-=int
	Array& operator-= (int);
	//--Array/=int
	Array& operator/= (int);
	//--Array*=int
	Array& operator*= (int);
	//--Array+=int
	Array& operator+= (int);


	//--Array-int
	Array operator- (int);
	//--Array/int
	Array operator/ (int);
	//--Array*int
	Array operator* (int);
	//--Array+int
	Array operator+ (int);
	//--Array+int

	//--array=int-array
	friend Array operator-(int, const Array&);
	//--array=int+array
	friend Array operator+(int, const Array&);
	//--array=int*array
	friend Array operator*(int, const Array&);
	//--array=int/array
	friend Array operator/(int, const Array&);

};

//прототип глобальной перегрузки оператора +
const Array operator+(const Array&, const Array&);