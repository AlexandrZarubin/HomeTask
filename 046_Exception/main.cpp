// Exception
#include <iostream>
#include <stdlib.h>
#include <limits> 

//using namespace std; //так можно но это избыточно
//using std::cout, std::endl;
using std::cout;
using std::endl;
using std::cin;
using std::istream;
using std::exception;
using std::numeric_limits;
using std::streamsize;

template <typename T> void SetValue(T& Value)
{
    cin.exceptions(istream::badbit | istream::failbit); //включаем обработку исключений для класса istream, через объект cin
    try //в него помещаем код, где будем ожидать генерацию исключения
    {
        cin >> Value; //throw istream::failure exp;
        //cin.operator>>(Value);
        //если после числа введен символ 5t или при вводе символа введены лищние символы +$
        //cin.ignore(32767, '\n');
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //очистка всего потока до его максимального содержимого
    }
    catch (const istream::failure& exp) //сюда будет пойман объект класса istream::failure
        //catch (const exception& exp) //такой catch поймает исключение от любого стандартного класса
    {
        //catch сработает когда оператор >> вызванный для объекта cin throw istream::failure exp;
        //cout << exp.what() << endl;
        //cout << exp.code() << endl;

        cout << "Некорректный ввод!" << endl;
        if (cin.fail()) //если поток перешел в состояние fail
        {
            cin.clear(); //возвращает поток в "рабочий" режим
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //очистка всего потока до его максимального содержимого
        }
        cout << "Попробуйте ещё раз!" << endl;
        SetValue(Value); //рекурсию можно заменить итерацией(бесконечным циклом)
    }
}

//проверка деления на ноль
template <typename T1, typename T2> auto Divide(T1 a, T2 b)
//float Divide(int a, float b)
{
    if (b == 0)throw 0; //генерация исключения с типом данных int
    //if (b == 0)throw 0.0f; //генерация исключения с типом данных float
    //if (b == 0) throw "Деление на ноль!"; //генерация исключения с типом данных const char*
    return a / b;
}
//корректный выбор операции
char SetOpertion()
{
    char O;
    while (true)
    {
        SetValue(O);
        switch (O)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return O;
        default:
            cout << "Неверно выбран вид операции! Попробуйте ещё раз!" << endl;
        }
    }
}
//корректный ввод ответа на вопрос
bool Answer()
{
    char A;
    while (true)
    {
        SetValue(A);
        switch (A)
        {
        case 'Y':
        case 'y':
            return true;
        case 'N':
        case 'n':
            return false;
        case 'Н':
        case 'н':
        case 'Т':
        case 'т':
            cout << "Переключите раскладку клавиатуры на английскую и попробуйте ещё раз!" << endl;
            break;
        default:
            cout << "Некорректный ответ! Попробуйте ещё раз!" << endl;
            break;
        }
    }
}


int main()
{
    system("chcp 1251");
    system("cls");
    int A = 0;
    float B = 0;
    char Operation = '+';
    float Result = 0.0F;
    while (true)
    {
        system("cls");
        try
        {
            cout << "Введите число А: ";
            //cin >> A;
            SetValue(A);
            cout << "Введите операцию: ";
            //cin >> Operation;
            //SetValue(Operation);
            Operation = SetOpertion();
            cout << "Введите число B: ";
            //cin >> B;
            SetValue(B);
            switch (Operation)
            {
            case '+':
                Result = A + B;
                break;
            case '/':
                //Result = A / B; //стандартные операторы не генерируют исключения
                Result = Divide(A, B);
                break;
            }
            cout << A << Operation << B << "=" << Result << endl;
            cout << "Продолжить вычисления Y/N? ";
            if (!Answer())break; //ввод и проверка ответа!
        }
        catch (int Code) //поймает любое исключени с типом данных int
        {
            if (Code == 0)cout << "Деление на ноль!" << endl;
            else cout << "Неизвестная ошибка!" << endl;
            cout << "Попробуйте ещё раз!" << endl;
            system("pause");
        }
        catch (const char* str)
        {
            cout << str << endl;
            system("pause");
        }
        catch (...) //универсальный catch поймает исключение любого типа данных
        {
            cout << "Непредвиденная ошибка! Обратитесь в службу технической поддержки!" << endl;
            exit(1);
        }
    }
    cout << "До новых встреч!" << endl;
}
