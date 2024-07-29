// Explicit
#include <iostream>
#include <windows.h>
#include <string> //содержит класс string, для работы со строками

using namespace std;

class SomeString
{
private:
	string MyString;
	//private(частный или закрытый) конструктор
	//SomeString(char){} //старый вариант, объект по такому конструктору не может быть создан вне класса,
	//а внутри самого класса или в дочерних классах - может быть создан
public:
	SomeString(char) = delete; //исключение конструктора, запрет на использование такого конструктора

	SomeString(const char* S) //передаем строковый литерал или массив символов при создании объекта
	{
		MyString = S;
		cout << "Конструктор const char*" << endl;
	}
	SomeString(int Size) //выделение места под строку размером Size
		//explicit SomeString(int Size) //explicit Запрещает неявное преобразование при вызове этого конструктора
	{
		MyString.resize(Size); //создание пустой строки размером Size
		cout << "Конструктор int" << endl;
	}
	//если нужен отдельный конструктор для (double), то лучше его написать, чем использовать неявные преобразования типов данных
	//SomeSring(double D) {}

	void Show()const
	{
		//SomeString T('Z'); //
		cout << MyString << endl;
	}
	void Length()const
	{
		cout << MyString.size() << endl; //размер строки внутри объекта класса string
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//SomeString STROKA = "Привет, Мир!"; //сработает конструктор const char*
	//STROKA.Show();
	//STROKA.Length();
	//SomeString STR(15); //сработает конструктор int
	//STR.Show();
	//STR.Length();

	//SomeString STR1_1 = 'G'; //explicit запретит преобразование //char, неявное расширяющее преобразование типа данных от char к int,
	//символ 'G' в целое число 71 и вызов конструктора SomeString(int Size)
	//SomeString STR1_2 = { 'G' }; //explicit запретит преобразование //унифицированная инициализация не сработает
	//SomeString STR1_3 = ( 'G' ); //explicit запретит преобразование
	//SomeString STR1_4 { 'G' };  //закрытый конструктор запрещает создание объекта таким образом //унифицированная инициализация не сработает
	//SomeString STR1_5 ( 'G' ); //закрытый конструктор запрещает создание объекта таким образом

	//STR1_1.Show();
	//STR1_1.Length();
	/*STR1_2.Show();
	STR1_2.Length();
	STR1_3.Show();
	STR1_3.Length();
	STR1_4.Show();
	STR1_4.Length();
	STR1_5.Show();
	STR1_5.Length();*/

	//SomeString STR2_1 = 3.14; //explicit запретит преобразование //double, неявное сужающее преобразование типа данных от double к int,
	//число 3.14 в целое число 3 и вызов конструктора SomeString(int Size)  
	//SomeString STR2_2 = { 3.14 }; //explicit запретит преобразование //унифицированная инциализация предотвращает автоматическое усечение данных
	//SomeString STR2_3 = ( 3.14 ); //explicit запретит преобразование
	//SomeString STR2_4{ 30LL }; //унифицированная инциализация предотвращает автоматическое усечение данных
	//SomeString STR2_5(3.14); //закрытый или delete конструктор запрещает создание объекта таким образом
	//STR2_1.Show();
	//STR2_1.Length();
	/*STR2_2.Show();
	STR2_2.Length();
	STR2_3.Show();
	STR2_3.Length();
	STR2_4.Show();
	STR2_4.Length();
	STR2_5.Show();
	STR2_5.Length();*/


}
