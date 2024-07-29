// MagicNumber
#include <iostream>
#include <windows.h>
#include <stdlib.h> //содержит в том числе и генератор случайных чисел
#include <time.h>   //библиотека для работы со временем

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL)); //сдвиг генератора случайных чисел на кол-во миллисекунд, прошедших с 00:00:00 01.01.1970
	int MagicNumber = 0;  //для хранения загаданного числа
	int PlayerNumber = 0; //для числа, введенного игроком
	char Answer = 'Д'; //хранит ответ на вопрос о продолжении игры
	int Menu;

	//проверка на ввод
	do
	{
		do {
			cout << "Выберите уровень сложности" << endl <<
				"1. Легкий        (Easy)" << endl <<
				"2. Нормальный    (Normal)" << endl <<
				"3. Сложный       (Hard)" << endl <<
				"4. Очень сложный (Very Hard)" << endl <<
				"5. Выход         (Exit)" << endl;
			cin >> Menu;
			if (Menu < 1 || Menu>5)
			{
				cout << "Некорректный ввод! Попробуйте ещё раз!" << endl;
			}
		} while (Menu < 1 || Menu>5);


		switch (Menu)
		{
		case 1:
			//цикл возврата в switch

				//цикл повторной игры
			while (Answer == 'Д' || Answer == 'д' || Answer == 'Y' || Answer == 'y') //пока ответ "Да" мы играем
			{
				system("cls"); //очистка экрана перед новой игрой
				cout << "---Угадай число от 1 до 9 за 5 попыток!---" << endl;
				MagicNumber = rand() % 9 + 1; //генерация случайного числа от 1 до 9 включительно
				//rand()%10; //от 0 до 9 включительно, не включая 10
				cout << MagicNumber << endl; //тестовый вывод

				for (int i = 1; i <= 5; i++) //цикл попыток 1 2 3 4 5
				{
					//цикл проверки пользовательского ввода
					do
					{
						cout << "Номер попытки: " << i << endl;
						cout << "Введите число от 1 до 9: "; cin >> PlayerNumber;
						if (PlayerNumber < 1 || PlayerNumber>9)
						{
							cout << "Некорректный ввод! Попробуйте ещё раз!" << endl;
							//уменьшаем кол-во оставшихся попыток, увеличивая кол-во использованных
							if (i == 5)break; //если попытка последняя, то выход из цикла пользовательского ввода do{}while
							else i++; //увеличиваем кол-во использованных попыток
						}
					} while (PlayerNumber < 1 || PlayerNumber>9);
					//сравнение чисел
					if (MagicNumber == PlayerNumber) //если число угадано
					{
						cout << "Поздравляем!!! Вы отгадали число " << MagicNumber << " с " << i << "-й попытки!" << endl;
						break; //выход из цикла попыток for()
					}
					else
					{
						if (i == 5)cout << "Вы проиграли! Загаданное число: " << MagicNumber << endl;
						else
						{
							cout << "Вы не угадали! У Вас осталось " << 5 - i << " попытки(а)!" << endl;
							//подсказки "Горячо/Холодно"
							if (PlayerNumber > MagicNumber)cout << "Ваше число больше загаданного!" << endl;
							else cout << "Ваше число меньше загаданного!" << endl;
						}
					}

				}
				cout << "Сыграем ещё(Y[Д]/N[Н])? "; cin >> Answer;


				break;
		default:
			cout << "Некорректное действие!" << endl;
			break;


			}



		}while (Answer == 'Д' || Answer == 'д' || Answer == 'Y' || Answer == 'y')
			cout << "сменить режим(Y[Д]/N[Н])? "; cin >> Answer;


	} while (Answer == 'Д' || Answer == 'д' || Answer == 'Y' || Answer == 'y');
		cout << "Игра закончена! До новых встреч!" << endl;


	//system("pause");
	Sleep(1000); //задержка выполнения программы в 1000 миллисекунд(1 секунда)

}
