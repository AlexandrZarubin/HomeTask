// TemplateSortFunction
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//прототип шаблона функции Сортировка Шелла
//template <typename T, typename L> void ShellSort(T Array[], L Size, bool Type=true);
template <typename T, typename L> void ShellSort(T[], L, bool = true);

int main()
{
	system("chcp 1251");
	system("cls");
	srand((unsigned int)time(NULL));
	cout << "---Программа сортировки массива!---" << endl;
	const int Size = 14;
	int Array[Size]{};
	bool Type = true;
	for (int i = 0; i < Size; i++)
	{
		Array[i] = rand() % (100 - (-99)) - 99;
		cout << Array[i] << " ";
	}
	cout << R"(
Выберите как отсортировать массив:
1 - от меньшего к большему(по возрастанию значений)
0 - от большего к меньшему(по убыванию значений)
)";
	cin >> Type;
	//вызов сортировки
	ShellSort(Array, Size, Type);
	//вывод отсортированного массива на экран
	for (int i = 0; i < Size; i++)
	{
		cout << Array[i] << " ";
	}
}
//Реализация шаблона функции Сортировка Шелла
template<typename T, typename L> void ShellSort(T Array[], L Size, bool Type)
{
	T temp = 0; //буфер для перестановки элементов местами
	//step - расстояние между сравниваемыми элементами
	for (L step = Size / 2; step > 0; step /= 2) //цикл шагов с уменьшающимся в два раза расстоянием между сравниваемыми элементами
	{
		for (L i = step; i < Size; i++) //цикл прохода по элементам массива(вперед)
		{
			if (Type) //если выбрана сортировка от меньшего к большему(по возрастанию)
			{
				for (L j = i - step; j >= 0 && Array[j + step] < Array[j]; j -= step)//цикл сравнения j-х элементов отстоящих от i-го на расстояние step
				{
					//меняем элементы местами, если правый меньше левого на расстояние step
					temp = Array[j];
					Array[j] = Array[j + step];
					Array[j + step] = temp;
				}
			}
			else //иначе от большего к меньшему(по убыванию значений)
			{
				for (L j = i - step; j >= 0 && Array[j + step] > Array[j]; j -= step)//цикл сравнения j-х элементов отстоящих от i-го на расстояние step
				{
					//меняем элементы местами, если правый больше левого на расстояние step
					temp = Array[j];
					Array[j] = Array[j + step];
					Array[j + step] = temp;
				}
			}
		}
	}
}
