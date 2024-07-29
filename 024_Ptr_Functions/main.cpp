// PtrFunctions
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

//�������� ������� �������� �������� ���� ���������� �������
//void Change(int A, int B);
void Change(int, int); //� ��������� ����� �� ��������� ����� ����������, �� ���� ������ �����������

//�������� ������� �������� �������� ���� ���������� �������, ��������� ������ ���������� ��� ������
//void Change_Pointers(int* pA, int* pB);
void Change_Pointers(int*, int*); //� ��������� ����� �� ��������� ����� ����������, �� ���� ������ �����������

//������� ������� ��������� ���������
inline void Equation(double k, double b, double* x)
{
	//double* x=&x1;
	*x = -b / k;
	//return �� ����� � ����� ���� ����������� ��� �������� ����� ��������
}
//���������� ������� ��� ������� ����������� ���������
double Equation(double a, double b, double c, double* x1, double* x2)
{
	//double* x1=&x1;
	//double* x2=&x2;
	double D = pow(b, 2) - 4 * a * c;
	//���� ��������� �������� �������� ������� ��� ��� �������
	if (a == 0.0)Equation(b, c, x1); //�������� ����� ����� ���������
	else
	{
		if (D >= 0.0)
		{
			//�������� ���������� ���������� �� ���� ������, ���������� � ��������� x1 � x2 ��� ������ �������
			*x1 = (-b - sqrt(D)) / (2 * a);
			*x2 = (-b + sqrt(D)) / (2 * a);
		}
	}
	return D; //return ������������ ��� ����������� ��������� �� ������(����� �� �����)
}

int main()
{
	system("chcp 1251");
	system("cls");
	//int One = 15, Two = -3;
	//cout<<"����� One: "<<One<<" ����� Two: "<<Two<<endl;
	//Change(One, Two); //� ������� ��� ������ ���������� ������ ��������(����������), � �� ���� ����������
	//cout<<"����� One: "<<One<<" ����� Two: "<<Two<<endl;
	//cout <<"\n"<< endl;
	//Change_Pointers(&One, &Two); //��� ������ ������� �������� � �� ������ ����������, ���������� ����� �������� ������ ������
	//cout << "����� One: " << One << " ����� Two: " << Two << endl;
	//int *pOne = &One, *pTwo = &Two; //���������� � ������������� ���� ����������
	//Change_Pointers(pOne, pTwo); //��� ������ ������� �������� � �� ������ ����������, ���������� ��� ���������� ���������� pOne � pTwo
	//cout << "����� One: " << One << " ����� Two: " << Two << endl;

	double a = 8.0, b = -8.0, k = 4.0, c = 2.0, x1 = 0.0, x2 = 0.0;
	Equation(k, b, &x1); //����� �������, �������� ��������� ���������� �� ������ ���������� x1, ����������� ��� ������ �������
	cout << "X= " << x1 << endl;
	double D = Equation(a, b, c, &x1, &x2); //�������� ������������ � ������ ����������, �� ������� ����� �������� ����������
	if (a == 0.0)cout << "X= " << x1 << endl;
	else
		if (D < 0)cout << "��� �������������� ������!" << endl;
		else cout << "X1= " << x1 << "\nX2= " << x2 << endl;
}
//���������� ������� �������� �������� ���� ���������� �������
void Change(int A, int B)  //����������� �������� � ����������� ���������� � � �(��������� �������)
{ //int A=One, B=Two; //������� �������� ������ � ������� ��������
	cout << "�������� ������� Change!" << endl;
	cout << "������ �����: " << A << " ������ �����: " << B << endl;
	int temp = A;
	A = B;
	B = temp;
	cout << "������ �����: " << A << " ������ �����: " << B << endl;
	cout << "������� Change ��������� ������!" << endl;
}
//���������� ������� �������� �������� ���� ���������� �������, ��������� ������ ���������� ��� ������
void Change_Pointers(int* pA, int* pB)
{
	//int* pA=&One;
	//int* pB=&Two;
	//int* pA=pOne;
	//int* pB=pTwo;
	int temp = *pA;
	*pA = *pB;
	*pB = temp;
}
