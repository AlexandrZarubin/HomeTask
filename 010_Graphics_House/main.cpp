// Home
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "---Программа построения домика!---" << endl;
	int N = 0; //размер поля(ширина домика)
	do
	{
		cout << "Введите ширину домика не меньше 11: "; cin >> N;
	} while (N < 11);
	//if (N % 2 == 0)N--;
	//крыша
	for (int i = 0; i < N; i++) //цикл по индексу строки
	{
		for (int j = 0; j < N; j++) //цикл по индексу столбца
		{
			if (N % 2 == 0) //если ширина четная
			{

				if (i == 3 * N / 4 - 1 && j == N / 2 + 1)cout << "___  ";  //правая верхняя горизонтальная рама
				else
					if (i == 3 * N / 4 - 1 && (j == N / 2 || j == N / 2 - 1))cout << "__ __";  //центральная верхняя горизонтальная рама
					else
						if (i == 3 * N / 4 - 1 && j == N / 2 - 2)cout << "  ___";  //левая верхняя горизонтальная рама
						else
							if (i == 3 * N / 4 && j == N / 2 + 1)cout << "   \\ "; //правый верхний угол
							else
								if (i == 3 * N / 4 && j == N / 2 - 2)cout << " /   "; //левый верхний угол
								else
									if (i == 3 * N / 4 && (j == N / 2 || j == N / 2 - 1))cout << "  |  "; //верхняя вертикальная рама
									else
										if (i == 3 * N / 4 + 1 && j == N / 2 + 1)cout << "---| "; //правая центральная горизонтальная рама
										else
											if (i == 3 * N / 4 + 1 && j == N / 2 - 2)cout << " |---"; //левая центральная горизонтальная рама
											else
												if (i == 3 * N / 4 + 2 && j == N / 2 + 1)cout << "___/ "; //правый нижний угол
												else
													if (i == 3 * N / 4 + 2 && j == N / 2 - 2)cout << " \\___"; //левый нижний угол
													else
														if (i == 3 * N / 4 + 2 && (j == N / 2 || j == N / 2 - 1))cout << "__|__"; //нижняя вертикальная рама
														else
															if (i == 3 * N / 4 + 1 && (j == N / 2 || j == N / 2 - 1))cout << "--|--"; //перекрестие окна
															else
																if ((i >= N / 2 - 1 && i <= N / 2 + 2) && j == N / 2 + 2)
																{
																	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
																	cout << "|###|"; //труба из кирпичей
																}
																else
																{
																	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
																	if (i > j && i + j > N - 1)cout << "|===|"; //черепица в крыше
																	else
																		if (i == j && i + j == N - 1)cout << "/===\\"; //конек крыши
																		else
																			if (i == j && i >= N / 2)cout << "|===\\";  //правая диагональ крыши
																			else
																				if (i + j == N - 1 && i >= N / 2)cout << "/===|"; //левая диагональ крыши
																				else
																				{
																					cout << "     "; //фон крыши - небо
																				}
																	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
																}
			}
			else //иначе ширина нечетная
			{
				if (i == 3 * N / 4 - 1 && j == N / 2 + 1)cout << "___  ";  //правая верхняя горизонтальная рама
				else
					if (i == 3 * N / 4 - 1 && j == N / 2)cout << "__ __";  //центральная верхняя горизонтальная рама
					else
						if (i == 3 * N / 4 - 1 && j == N / 2 - 1)cout << "  ___";  //левая верхняя горизонтальная рама
						else
							if (i == 3 * N / 4 && j == N / 2 + 1)cout << "   \\ "; //правый верхний угол
							else
								if (i == 3 * N / 4 && j == N / 2 - 1)cout << " /   "; //левый верхний угол
								else
									if (i == 3 * N / 4 && j == N / 2)cout << "  |  "; //верхняя вертикальная рама
									else
										if (i == 3 * N / 4 + 1 && j == N / 2 + 1)cout << "---| "; //правая центральная горизонтальная рама
										else
											if (i == 3 * N / 4 + 1 && j == N / 2 - 1)cout << " |---"; //левая центральная горизонтальная рама
											else
												if (i == 3 * N / 4 + 2 && j == N / 2 + 1)cout << "___/ "; //правый нижний угол
												else
													if (i == 3 * N / 4 + 2 && j == N / 2 - 1)cout << " \\___"; //левый нижний угол
													else
														if (i == 3 * N / 4 + 2 && j == N / 2)cout << "__|__"; //нижняя вертикальная рама
														else
															if (i == 3 * N / 4 + 1 && j == N / 2)cout << "--|--"; //перекрестие окна
															else
																if ((i >= N / 2 - 1 && i <= N / 2 + 2) && j == N / 2 + 2)
																{
																	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
																	cout << "|###|"; //труба из кирпичей
																}
																else
																{
																	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
																	if (i > j && i + j > N - 1)cout << "|===|"; //черепица в крыше
																	else
																		if (i == j && i + j == N - 1)cout << "/===\\"; //конек крыши
																		else
																			if (i == j && i >= N / 2)cout << "|===\\";  //правая диагональ крыши
																			else
																				if (i + j == N - 1 && i >= N / 2)cout << "/===|"; //левая диагональ крыши
																				else cout << "     "; //фон крыши - небо
																	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
																}
			}
		}
		cout << endl;
	}
	//стены
	for (int i = 0; i < N; i++) //цикл по индексу строки
	{
		for (int j = 0; j < N; j++) //цикл по индексу столбца
		{
			//дверь
			if (i == N - 1 && j == 1)cout << "|____"; //левая половина нижней границы двери
			else
				if (i == N - 1 && j == 2)cout << "____|"; //правая половина нижней границы двери
				else
					if (i == N / 2 + 2 && j == 1)cout << "| O  "; //ручкана две строки ниже середины стены
					else
						if (i >= 4 && j == 1)cout << "|    "; //левая сторона двери
						else
							if (i >= 4 && j == 2)cout << "    |"; //правая сторона двери
							else
								if (i == 3 && (j == 1 || j == 2))cout << "_____"; //верх двери
								else
									//окно
									if ((i == N / 2 - 2 || i == N / 2 + 2) && (j >= N - 5 && j <= N - 2))cout << "-----"; //верхняя и нижня рамы окна
									else
										if ((i >= N / 2 - 1 && i <= N / 2 + 1) && j == N - 5)cout << "|    "; //левая рама окна
										else
											if ((i >= N / 2 - 1 && i <= N / 2 + 1) && j == N - 2)cout << "    |"; //правая рама окна
											else
												//перечисление двух столбцов через ИЛИ ||
												if ((i >= N / 2 - 1 && i <= N / 2 + 1) && (j == N - 4 || j == N - 3))cout << "  |  "; //центральные вертикальные рамы
			//диапозон из двух столбцов через И &&
			//if((i>=N/2-1&&i<=N/2+1)&&(j>=N-4&&j<=N-3))cout<<"  |  "; //центральные вертикальные рамы	
												else
												{
													SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
													cout << "|###|";  //фон стены - кирпичи
													SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
												}
		}
		cout << endl;
	}
}
