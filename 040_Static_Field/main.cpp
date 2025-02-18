﻿// StaticField
#include <iostream>
#include <stdlib.h>

using namespace std;

//класс со статическим полем
class StaticField
{
	//private:
		//собственное(нестатическое) поле каждого объекта класс
	int number;
	//public:
		//статическое поле, общее для всех объектов класса
	static int field;
	//static int field=0; //нельзя инициализировать статическое поле внутри класса
public:
	//конструктор для инициализации собственного поля каждого объекта класса
	StaticField(int n) :number{ n }//, field{ 10 }; //нельзя инициализировать статическое в конструкторе
	{
		//field = 10; //можно в конструктор и в любом методе класса работать со статическим полем
	}
	//метод вывода содержимого на экран(нестатический)
	void Show()const //void Show(const StaticField* const this)
	{
		cout << "number= " << number << endl;
		//обычный(нестатический) метод имеет доступ к статическим(общим) и нестатическим(собственным) полям 
		cout << "field= " << field << endl;
		//нельзя изменять нестататическое(собственное) поле в const методе
		//number = 15; //this->number = 15;

		//можем изменять статическо поле даже в const методе
		//field = 15;  //StaticField::field=15;
	}
	//статический метод - метод для работы со статическим полем без использования объекта 
	static void Display() //const - статический метод может быть вызван без объекта и не может быть константным,
	{ //так как не умеет указателя this в качестве аргумента

		cout << "field= " << field << endl;
		//cout << "number= " << number << endl; //нельзя работать с собственными(нестатическими) полями без объекта
		//this; //в статическом методе нет указателя this
	}
	//статический метод: Если передан адрес объекта, то изменяет собственного поле number этого объекта,
	//иначе изменяет значение статического поля field - общего для всех объектов класса
	static void Setter(int i, StaticField* const THIS = nullptr) //статический метод не имеет "встроенного" указателя this
		//объекты в статический метод нужно передавать явно вручную, по значению, адресу или ссылке
	{
		//если передан адрес
		if (THIS)THIS->number = i; //THIS - аналог указателя this для статического метода
		else field = i;
	}
};
//глобальная инициализация статического поля обязательна
int StaticField::field = 5;

int main()
{
	system("chcp 1251");
	system("cls");

	//обращение к статическому полю без создания объекта, через указание имени класса(если поле public)
	/*cout << "Значение статического поля: " << StaticField::field << endl;
	StaticField::field = 10;
	cout << "Значение статического поля: " << StaticField::field << endl;*/

	//вызываем статический метод Display через указание имени класса, без создания объекта
	StaticField::Display();
	//StaticField::Show(); //нельзя вызвать нестатический метод через имя класса

	StaticField::Setter(100); //изменение статического поля
	StaticField::Display();

	//блок кода ограничит область видимости
	{
		//создаем объект класса
		StaticField Object(-3);
		cout << endl;
		//вызов нестатического метода Show возможен только через объект класса
		Object.Show();
		cout << endl;
		//вызов статического метода Display через объект
		Object.Display();
		cout << endl;
		//вызов статического метода Setter через объект
		Object.Setter(333); //такой вызов изменит статическое поле field
		Object.Show();
		cout << endl;
		//вызов статического метода Setter через объект, с передачей адреса объекта Object
		Object.Setter(555, &Object); //такой вараинт изменит собственное поле number объекта Object
		Object.Show();
		cout << endl;
		//вызов статического метода Setter через имя класса, с передачей адреса объекта Object
		StaticField::Setter(111, &Object); //такой вараинт изменит собственное поле number объекта Object
		Object.Show();
		cout << endl;
	}
	//после уничтожения объекта статические поля и методы продолжают быть доступны через имя класса
	StaticField::Display();
	StaticField::Setter(-100);
	StaticField::Display();
	//когда нет ни одного объекта мы можем работать со статическими методами через имя класса

}
