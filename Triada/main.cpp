#include <iostream>
#include <locale.h>
#include <stdlib.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "---Программа сравнения двух чисел!---" << endl;
	int A = 0, B = 0, min = 0, max = 0;
	cout << "Введите число А: "; cin >> A;
	cout << "Введите число B: "; cin >> B;

	//тернарный оператор
	//1 Вариант
	//(Условие) ? Действие если условие истина : Действие если условие ложь ;

	max = (A > B) ? A : B;			//аналлогично if(A>B)max=A; else max=B;
	//max=(B>A)?B:A;		//аналлогично if(B>A)max=B; else max=A;	

	min = (A < B) ? A : B;			//аналлогично if(A<B)min=A; else min=B;	
	//min=(B<A)?B:A;		//аналлогично if(B>A)min=B; else min=A;	

	cout << "Максимум равен: " << max << endl;
	cout << "Минимум равен: " << min << endl;

	if (A > B) { max = A; min = B; }
	else { max = B; min = A; }
	cout << "Максимум равен: " << max << "\nМинимум равен: " << min << endl;
	//2 Вариант
	(A > B) ? cout << "Максимум равен: " << A << "\nМинимум равен: " << B << endl :
		cout << "Максимум равен: " << B << "\nМинимум равен: " << A << endl;
	system("cls");

	if (A == B) // 
	{
		cout << "Оба числа равны между собой и равны: " << A << endl;
	}
	else // когда А не равно В
	{
		//if (A > B)//когда A больше B
		//{
		//	max = A;
		//	min = B;
		//}
		//else//когда B ольше А
		//{
		//	max = B;
		//	min = B;
		//}
		// аналагичено
		max = (A > B) ? A : B;
		min = (A < B) ? A : B;
		cout << "Максимум равен:" << max << "\nМиниум равен: " << min << endl;
	}
	//(Условие) ? Действие если условие истина : Действие если условие ложь ;

}
