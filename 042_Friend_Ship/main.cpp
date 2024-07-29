// FriendShip
#include <iostream>
//#include <math.h>
//#include <stdlib.h>
#include <cstdlib>

using namespace std;
//прототип класса линия на плоскости
class line_on_plane;

//класс точка на плоскости
class point_on_plane
{
    //координаты точки
    float X, Y;
public:
    //конструктор с параметрами, со значением параметров по умолчанию
    //с унифицированной инициализхацеий полей
    point_on_plane(float x = 0.0F, float y = 0.0F) : X{ x }, Y{ y } {}
    //прототип дружественной функции
    friend float Deviation(point_on_plane, line_on_plane); //имена парамтеров можно не указывать

    //friend line_on_plane; //предоставление полного доступа классу line_on_plane к содержимому класса point_on_plane
};

//класс линия на плоскости
class line_on_plane
{
    //коэффиенты
    float A, B, C;
public:
    //конструктор с параметрами, с унифицироанной инициализацеией поелй
    line_on_plane(float a, float b, float c) : A{ a }, B{ b }, C{ c } {}
    //прототип дружественной функции
    friend float Deviation(point_on_plane, line_on_plane); //имена парамтеров можно не указывать
};

int main()
{
    system("chcp 1251");
    system("cls");
    //определяем точку
    point_on_plane P(3.5, 1.5);
    //определяем линию
    line_on_plane L(1, 2, 3.5);

    float DEV = Deviation(P, L);
    if (!DEV)cout << "Точка пренадлежит прямой!" << endl;
    else cout << "Отклонение точки от прямой: " << DEV << endl;
}

//реализация дружественной функции
float Deviation(point_on_plane P, line_on_plane L)
{
    //возвращает отклонение точки от прямой
    return abs(L.A * P.X + L.B * P.Y + L.C);
    //return abs(L.getA() * P.getX() + L.getB() * P.getY() + L.getC());
}
