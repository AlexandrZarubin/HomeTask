﻿// Factorial_R
#include <iostream>
#include <locale.h>
#include <stdlib.h>

using namespace std;

//рекурсивная функция вычисления факториала числа
double Factorial_R(int n)
{
	if (n < 0)return 0; //если факториал не существует, выход с кодом 0
	else if (n <= 1)return 1; //условие окончания рекурсии
	else return n * Factorial_R(n - 1); //n*(n-1)!
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "---Программа вычисления факториала числа!---" << endl;
	//F=n!=n*(n-1)!
	int n = 0; //число, факториал которого мы вчисляем
	unsigned int i = 1; //счетчик для перебора чисел от 1 до n включительно
	//unsigned long long F = 1ull;//1ULL результат(факториал)
	double F = 1.0; //переменная для хранения результата, представленного в экспоненциальной форме 

	cout << "Введите число n, не больше 170: "; cin >> n;

	//if (n > 170)cout << "Для вычисления факториала больше 170 используйте полную версию программы!" << endl;
	//else
	//	if (n < 0)cout << "Факториал не существует!" << endl;
	//	else
	//		if (n == 0 || n == 1)cout << "Факториал = 1" << endl;
	//		else
	//		{
	//			while (i <= n) //от 1 до n включительно
	//			{
	//				F *= i; //F=F*i;
	//				i++;
	//				//cout << F << endl; //вывод промежуточных значений на экран
	//			}
	//			cout << "Факториал = " << F << endl;
	//		}

	if (n > 170)cout << "Для вычисления факториала больше 170 используйте полную версию программы!" << endl;
	else
	{
		F = Factorial_R(n);
		if (F == 0)cout << "Факториал не существует!" << endl;
		else cout << "Факториал = " << F << endl;
	}

	system("pause");
}
