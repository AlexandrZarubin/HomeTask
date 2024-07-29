// Propusk
#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

//класс пропуск
class Propusk
{
    //private:
        //поля:
    char FIO[255];  //ФИО - статический массив символов
    int ID;         //номер пропуска
    char* FOTO;     //путь к файлу с фотографией - динамический массив символов(строка)
public:
    //прототипы методов
    //конструктор с параметрами
    Propusk(const char[], int, const char*);
    //Конструктор по умолчанию с унифицированной инициализацией полей
    Propusk() : FIO{}, ID{ 0 }, FOTO{ nullptr } { cout << "Конструктор по умолчанию!" << endl; }
    //деструктор
    ~Propusk();
    //Сеттеры
    void SetFIO(const char[]);
    void SetID(int);
    void SetFOTO(const char*);
    //Геттеры
    char* GetFIO();
    int GetID();
    char* GetFOTO();
    //метод вывода на экран
    void Show();
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Propusk P{ "Иванов Иван Иванович",101,"C:\\FOTO\\101.jpg" };
    P.Show();
    //P.~Propusk(); //явный вызов деструктора не уничтожает объект, крайнет не рекомендуется
    P.Show();
    Propusk D[3]; //массив из 3х пропусков
    //промежуточные буферы для вводы
    char FIO[255]{};
    int ID = 0;
    char FOTO[255]{};
    for (int i = 0; i < 3; i++)
    {
        cout << "Введите данные " << i + 1 << "-го пропуска:" << endl;
        cout << "Введите фамилию: ";
        cin.getline(FIO, 255);
        D[i].SetFIO(FIO);
        cout << "Введите ID: ";
        cin >> ID;
        cin.ignore();
        D[i].SetID(ID);
        cout << "Введите путь к фотографии: ";
        cin.getline(FOTO, 255);
        D[i].SetFOTO(FOTO);
    }
    system("cls");
    cout << "Введите ID: "; cin >> ID;
    bool Flag = false;
    for (int i = 0; i < 3; i++)
    {
        if (D[i].GetID() == ID)
        {
            Flag = true;
            D[i].Show();
        }
    }
    if (Flag == false)cout << "Пропуск не найден!" << endl;
}
//реализация методов
//конструктор с параметрами
Propusk::Propusk(const char fio[], int id, const char* foto) //:: расширение области видимости или укзание принадлежности классу
{
    cout << "Конструктор с параметрами!" << endl;
    ID = id;
    strcpy_s(FIO, fio);
    FOTO = new char[strlen(foto) + 1] {}; //динамическое выделение памяти под поле FOTO
    //добавить проверку выделения памяти
    strcpy_s(FOTO, strlen(foto) + 1, foto);
}
//деструктор
Propusk::~Propusk()
{
    //освобождение память
    if (FOTO) delete[] FOTO;
    FOTO = nullptr;
    cout << "Сработал деструктор!" << endl;
}
//Сеттеры
void Propusk::SetFIO(const char fio[])
{
    strcpy_s(FIO, fio);
}
void Propusk::SetID(int id)
{
    ID = id;
}
void Propusk::SetFOTO(const char* foto)
{
    if (FOTO)delete[] FOTO; //совобождение памяти из под старой строки
    FOTO = new char[strlen(foto) + 1] {}; //динамическое выделение памяти под поле FOTO
    strcpy_s(FOTO, strlen(foto) + 1, foto);
}
//Геттеры
char* Propusk::GetFIO()
{
    return FIO;
}
int Propusk::GetID()
{
    return ID;
}

char* Propusk::GetFOTO()
{
    return FOTO;
}
//метод вывода на экран
void Propusk::Show()
{
    cout << FIO << "\t" << ID;
    if (FOTO)cout << "\t" << FOTO; //если строка задана, выводим на экран
    cout << endl;
}
