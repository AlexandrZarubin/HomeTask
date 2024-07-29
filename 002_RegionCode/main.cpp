// RegionCode
#include <iostream>
#include <locale.h>
#include <stdlib.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "---Программа для определения региона по коду автомобильного номера!---" << endl;
	int Code = 0; //код региона
	char  symbol = ' ';
	while (symbol != '0')
	{


		cout << "Введите код региона: "; cin >> Code;

		enum RegionCodes
		{
			Chel = 74,
			Chel1 = 174,
			Chel2 = 774,
			Ekb = 66,
			Ekb1 = 96,
			Ekb2 = 166,
			Ekb3 = 196,
			Nsk = 54,
			Nsk1 = 154,
			Mmk = 51,
			Smr = 63,
			Smr1 = 163,
			Smr2 = 763,
			Srt = 64,
			Srt1 = 164,
			Alt = 22,
			Alt1 = 122,
			Ksrk = 24,
			Ksrk1 = 124,
			Tat = 16,
			Tat1 = 116,
			Tat2 = 716,
			//DZ
			Msk = 77,
			Msk1 = 99,
			Msk2 = 97,
			Msk3 = 177,
			Msk4 = 199,
			Msk5 = 197,
			Msk6 = 777,
			Msk7 = 799,
			Msk8 = 797,
			Msk9 = 977,
			//
			Msko = 50,
			Msko1 = 90,
			Msko2 = 150,
			Msko3 = 190,
			Msko4 = 750,
			Msko5 = 790,
			//
			Spb = 78,
			Spb1 = 98,
			Spb2 = 178,
			Spb3 = 198,
			//
			Len = 47,
			Len1 = 147,

		};

		switch (Code)
		{
		case Chel:
		case Chel1:
		case Chel2:
			cout << "Челябинская область!" << endl;
			break;
		case RegionCodes::Alt:
		case RegionCodes::Alt1:
			cout << "Алтайский край!" << endl;
			break;
		case RegionCodes::Ekb:
		case RegionCodes::Ekb1:
		case RegionCodes::Ekb2:
		case RegionCodes::Ekb3:
			cout << "Свердловская область!" << endl;
			break;
		case RegionCodes::Ksrk:
		case RegionCodes::Ksrk1:
			cout << "Красноярский край!" << endl;
			break;
		case RegionCodes::Mmk:
			cout << "Мурманская область!" << endl;
			break;
		case RegionCodes::Nsk:
		case RegionCodes::Nsk1:
			cout << "Новосибирская область!" << endl;
			break;
		case RegionCodes::Smr:
		case RegionCodes::Smr1:
		case RegionCodes::Smr2:
			cout << "Самарская область!" << endl;
			break;
		case RegionCodes::Srt:
		case RegionCodes::Srt1:
			cout << "Саратовская область!" << endl;
			break;
		case RegionCodes::Tat:
		case RegionCodes::Tat1:
		case RegionCodes::Tat2:
			cout << "Республика Татарстан!" << endl;
			break;
			//DZ
		case RegionCodes::Msk:
		case RegionCodes::Msk1:
		case RegionCodes::Msk2:
		case RegionCodes::Msk3:
		case RegionCodes::Msk4:
		case RegionCodes::Msk5:
		case RegionCodes::Msk6:
		case RegionCodes::Msk7:
		case RegionCodes::Msk8:
		case RegionCodes::Msk9:
			cout << "Москва!" << endl;
			break;
		case RegionCodes::Msko:
		case RegionCodes::Msko1:
		case RegionCodes::Msko2:
		case RegionCodes::Msko3:
		case RegionCodes::Msko4:
		case RegionCodes::Msko5:
			cout << "Московская область!" << endl;
			break;
		case RegionCodes::Spb:
		case RegionCodes::Spb1:
		case RegionCodes::Spb2:
		case RegionCodes::Spb3:
			cout << "Санкт-Петербург!" << endl;
			break;
		case RegionCodes::Len:
		case RegionCodes::Len1:
			cout << "Ленинградская область!" << endl;
			break;


		default:
			cout << "Регион не найден!" << endl;
			cout << "Данный регион будет доступен в полной версии программы!" << endl;
			break;
		}
		//system("pause");
		//Вопрос о продолжений
		cout << "Для выхода введите | 0 |, для продолжения введите любой сивол!" << endl;
		cin >> symbol;
		system("cls");
	}
}
