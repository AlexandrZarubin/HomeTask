// Files
#include <iostream> //содержит консольные потоки ввода-вывода
#include <fstream>  //содержит файловые потоки ввода-вывода
#include <windows.h> //кодировка
#include <string>    //класс стринг
#include <stdlib.h>  //
#include <time.h>   //тайм машин
#include <vector> //содержит класс вектор(динамический авторасширяемый массив)

using namespace std;
class Student
{
    string FIO;      //студент
    int CountGrades; //количесвто оценок 
    int* Grades;     //оценки
public:
    //конструктор по умолчанию для создания пустого объекта
    Student() :FIO{}, CountGrades{ 0 }, Grades{ nullptr } {}
    //конструктор c параметрами 
    Student(string fio, int CG) :FIO{ fio }, CountGrades{ CG }
    {
        Grades = new int[CountGrades] {};
        for (int i = 0; i < CountGrades; i++)
        {
            Grades[i] = rand() % 4 + 2;
        }
    }
    void Show()const
    {
        cout << "ФИО: " << FIO << "\nОценки: ";
        for (int i = 0; i < CountGrades; i++)
        {
            cout << Grades[i] << " ";
        }
        cout << endl;
    }
    //метод записи объекта с динамическими полями в файл 
    void Save(string Path, bool Mode = true) //принемает имя файла
    {
        fstream Stream; //двунаправленный файловый поток
        //выбор дозаписать или перезаписать файл
        if (Mode)Stream.open(Path, ios::app, ios::binary);
        else Stream.open(Path, ios::out, ios::binary);

        if (!Stream.is_open())
        {
            cout << "Ошибка создания файла!" << endl;
            return;
        }
        cout << "Файл успешно создан!" << endl;
        int Size = FIO.size(); //размер строки внутри объекта класса string
        Stream.write((char*)&Size, sizeof(Size)); //записываем в файл размер строки внутри string
        Stream.write(FIO.c_str(), FIO.size()); //записываем строку из string в файл
        //запись массива оценок
        Stream.write((char*)&CountGrades, sizeof(int)); //Stream.write((char*)&CountGrades, sizeof(CountGrades));
        Stream.write((char*)Grades, CountGrades * sizeof(int)); //запись массива оценок с укзание его полного размера
        Stream.close();
        cout << "Файл успешно записан!" << endl;
    }

    //метод считывания объекта с динамическими полями из файла
    void Load(string Path) //принемает имя файла   
    {
        fstream Stream; //двунаправленный файловый поток
        Stream.open(Path, ios::in, ios::binary);
        if (!Stream.is_open())
        {
            cout << "Ошибка открытия файла!" << endl;
            //return;
            return;
        }
        cout << "Файл успешно открыт!" << endl;
        if (Grades) //если есть оценки их нужно удалить
        {
            delete[]Grades;
            Grades = nullptr;
            CountGrades = 0;
        }
        FIO.clear(); //очистка строки
        int Size = 0;
        Stream.read((char*)&Size, sizeof(int)); //считываем размер строки FIO
        char* Buffer = new char[Size + 1] {}; //буфер для считывания строки
        Stream.read(Buffer, Size); //Stream.read(Buffer, Size * sizeof(char)); //считываем строку FIO
        Stream.read((char*)&Size, sizeof(int)); //считываем размер массива оценок
        if (Size == 0)
        {
            //выход, если нет оценок
            Stream.close();
            return;
        }
        FIO = Buffer; //сохраняем строку в FIO
        delete[] Buffer;
        CountGrades = Size; //сохраняем кол-во оценок
        Grades = new int[CountGrades] {}; //выделяем память под массив оценок
        Stream.read((char*)Grades, CountGrades * sizeof(int)); //считываем оценки в память где находится массив оценок
        long cursor = Stream.tellg();
        Stream.close();
        cout << "Файл успешно считан!" << endl;
    }

    long Load(fstream& Stream)
    {
        //fstream Stream; //двунаправленный файловый поток
        //Stream.open(Path, ios::in, ios::binary);
        if (!Stream.is_open())
        {
            cout << "Ошибка открытия файла!" << endl;
            //return;
            return 0;
        }
        cout << "Файл успешно открыт!" << endl;
        if (Grades) //если есть оценки их нужно удалить
        {
            delete[]Grades;
            Grades = nullptr;
            CountGrades = 0;
        }
        FIO.clear(); //очистка строки
        int Size = 0;
        Stream.read((char*)&Size, sizeof(int)); //считываем размер строки FIO
        char* Buffer = new char[Size + 1] {}; //буфер для считывания строки
        Stream.read(Buffer, Size); //Stream.read(Buffer, Size * sizeof(char)); //считываем строку FIO
        Stream.read((char*)&Size, sizeof(int)); //считываем размер массива оценок
        if (Size == 0)
        {
            //выход, если нет оценок            
            return Stream.tellg(); //возвращаем положение курсора в файле
        }
        FIO = Buffer; //сохраняем строку в FIO
        delete[] Buffer;
        CountGrades = Size; //сохраняем кол-во оценок
        Grades = new int[CountGrades] {}; //выделяем память под массив оценок
        Stream.read((char*)Grades, CountGrades * sizeof(int)); //считываем оценки в память где находится массив оценок
        cout << "Файл успешно считан!" << endl;
        return   Stream.tellg();//возвращаем положение курсора в файле
    }

    ~Student()
    {
        if (Grades) delete[] Grades;
        Grades = nullptr;
        CountGrades = 0;
        FIO = "";
    }

};


int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    //класс, объекты которых - потоки консольного ввода-вывода
    //istream cin; //cin - Объект класса istream(поток ввода)

    /*int A = 0;
    cin >> A;
    cin.operator>>(A);*/

    //ostream cout; //cout - объект класса ostream(поток вывода)
    //cout << "Привет, Мир!" << endl;
    //cerr << "Ошибка!" << endl; //небуферизированный поток, для вывода ошибок
    //clog << "Тест!" << endl; //буферизированный поток для вывода и служебных сообщений

    //классы, объекты которых файловые потоки ввода вывода
    //ifstream F_In; //входной файловый поток
    //ofstream F_Out; //выходной файловый поток
    //fstream F_IO; //двунаправленный файловый поток

    //string Path = argv[0]; //получаем полное имя exe файла нашей программы
    //Path.resize(Path.size() - 4); //удаляем расширение .exe
    //Path += "_log.txt"; //добавляем новый текст и расширение к имени файла
    //cout << Path << endl;

    string Path;
    cout << "Ведите имя файла: ";
    getline(cin, Path);

    //Работа с файлами в текстовом ржиме(с текстовыми файлами)
    //запись в файл
    //создаем файловый поток вывода в файл(объект класса ofstream)
   //ofstream F_Out; //конструктор по умолчанию
    //ofstream F_Out(Path); //-создание потока с открытием файла на запись
    // создем(открываем) файл, "привязывем" к нему поток
    //F_Out.open(Path); //открытие файла на запись ios::out

    //F_Out.open(Path, ios::_Noreplace);
    /*
        ios_base::out(ios::out) - открытие файла на запись, существующий файл будет перезаписан, если файла нет он будет создан
        ios::in - открытие файла на чтение, если файла не существует будет ошибка
        ios::ate - откртие файла и установка курсора в конец файла
        ios::app - открытие файла на дозапись, существующий файл будет дозаписан, если файла нет он будет создан
        ios::trunc - удаление содержимого файла
        ios::_Noreplace - не заменять существующий файл, а выдать ошибку
        ios::_Nocreate - не создавать файл если его нет, а выдать ошибку
        ios::binary - открытие файла в двоичном режиме
    */

    //if (!F_Out.is_open()) //true еслми файл откры и false если не удалось открыть
    //{
    //    cout << "Ошибка создания файла!" << endl;
    //}
    //else
    //{
    //    cout << "Файл успешно создан!" << endl;
    //    //запись строки, числового литерала и значений переменной в файл
    //    F_Out << "Привет, Мир!\n" << 15 << endl;
    //    double PI = 3.14;
    //    F_Out << PI << endl;
    //    F_Out.close(); //закрытие потока и файла
    //    cout << "Файл успешно записан!" << endl;
    //}

    ////считываение текстового файла
    //ifstream F_In(Path); //ios::in на чтение
    //if (!F_In.is_open())
    //{
    //    cout << "Ошибка открытия файла!" << endl;
    //}
    //else
    //{
    //    cout << "Файл успешно открыт!" << endl;
    //    char S = ' '; //буфер для посимвольного считывания
    //    string Buffer; //буфер для построчного считывания
    //    int A = 0;
    //    double Z = 0.0;
    //    //I посимвольное считывание
    //    //while (F_In.get(S))
    //    //{
    //    //    cout << S;
    //    //    //или применить функции определения вида символа
    //    //}
    //    //F_In.close();
    //    //cout << "Файл успешно считан!" << endl;

    //    //II построчное считывание всего соддержимого файла как текста
    ////    vector<string> STR; //Вектор STR - динамический авторасширяемый массив динамических авторасширяемых строк
    ////    //STR - это объект класса вектор, содержащий массив объектов класса string
    ////    while (!F_In.eof()) //пока не дошли до конца файла
    ////    {
    ////        //char str[255]{};
    ////        //F_In.getline(str, 255); //для char[] или char*
    ////        //fgets(str, 255, F_In); //для указателей на файлы из языка С
    ////        getline(F_In, Buffer); //считываение в объект класса string из файла
    ////        STR.push_back(Buffer); //записываем содержимое строки Buffer в вектора STR
    ////    }
    ////    F_In.close();
    ////    cout << "Файл успешно считан!" << endl;
    ////    for (int i = 0; i < STR.size(); i++)
    ////    {
    ////        if (i == 1)A = stoi(STR[i]);  //stoi - преобразование всей строки из string в int
    ////        if (i == 2)Z = stod(STR[i]);
    ////        cout << STR[i] << endl;
    ////    }
    ////    cout<<"A+Z= "<<A+Z<<endl;
    ////}

    //    //III считывание разнотипного содержимого по типам данных из текстового файла
    //    int i = 0;
    //    while (!F_In.eof()) //true - когда конец файла, false когда еще не дошли до конца
    //    {
    //        if (i == 0)
    //        {
    //            getline(F_In, Buffer); //текст считываем как строку в объект класса string
    //            //F_In >> Buffer; // считываение строки до пробела
    //        }
    //        else
    //        {
    //            if (i == 1)F_In >> A; //считываем в переменню типа данных int
    //            else F_In >> Z;
    //        }
    //        i++;
    //    }
    //    F_In.close();
    //    cout << "Файл успешно считан!" << endl;
    //    cout << Buffer << endl;
    //    cout << A << "\n" << Z << endl;
    //    cout << "A+Z= " << A + Z << endl;
    //}

    Student Temp{ "Иванов Иван Иванович", 5 };
    Temp.Show();
    //для объекта класса со статической памятью в полях
    //fstream Stream; //двунаправленный файловый поток
    //Stream.open(Path, ios::out, ios::binary); //открываем файл на запись в двоичном режиме
    //Stream.open(Path, ios::out | ios::binary); //так тоже можно
    //Stream.open(Path, ios::app, ios::binary);  //открываем файл на дозапись в двоичном режиме
    //для объекта класса со статической памятью в полях
    //Stream.write((char*)&Temp, sizeof(Temp)); //запись объекта Temp класа Student в файл целиком!
    //Stream.write((char*)&Temp, sizeof(Student)); //аналогично
    //Stream.close(); //закрытие файла после записи

    //Stream.open(Path, ios::in, ios::binary); //открываем файл на чтение в двоичном режиме
    //Student Buffer;//создаем пустой объект
    //Stream.read((char*)&Buffer, sizeof(Buffer)); //считывание в объект Buffer класса Student объекта из файла целиком!
    //Stream.read((char*)&Buffer, sizeof(Student));  //аналогично
    //Buffer.Show();

    Temp.Save(Path); //дозапись студента
    //Temp.Save(Path,false); //перезапсь всего файла

    //Student Buffer;
    //Buffer.Load(Path);
    //system("pause");
    ////system("cls");
    //Buffer.Show();

    Student Buffer;
    fstream Stream; //двунаправленный файловый поток
    Stream.open(Path, ios::in, ios::binary);
    while (!Stream.eof())
    {
        long Cursor = Buffer.Load(Stream);
        if (!Cursor)break;
        if (Cursor != EOF)
        {
            //можно сохранить студентов в массив или в динамическую структуру хранения данных
            Buffer.Show();
        }
    }
    Stream.close();



}

