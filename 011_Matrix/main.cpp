// Matrix
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    const int N = 11;  //������ �������(���-�� ����� � ��������)

    //������� ���������� �������
    int Matrix[N][N]{};
    int Max = -100; //������ ��������� �������� ������� ������, ��� � ������ ��������
    int Min = 100; //������ ��������� �������� ������� ������, ��� � ������ ��������
    int Summa = 0; //��� �������� ����� ��������� ���������
    int Count = 0; //��� �������� ���-�� ��������� ���������
    float Average = 0.0F; //��� �������� �������� ��������������� �������� ����� ��������� ���������
    char Dark_Side = ' ';//������ ������ ������ ���������

    //���������� ������� ����������
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            //��������� ��������� ��� "����������" �������� ��������, ��������� �� ����� ����� 
            do
            {
                Matrix[i][j] = rand() % (100 - (-99)) - 99; //-99...99
            } while (Matrix[i][j] > -10 && Matrix[i][j] < 10); //��������� ����� �� -9 �� 9           
        }
    }

    //���� ������ � ��������
    while (Dark_Side != '0')
    {
        system("cls");
        cout << "---��������� ��� ������ � ���������� ��������!---" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (Matrix[i][j] > 0)cout << " "; //��������� ������ ����� ������������� ������
                cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }
        //����� ���� �� ����� 
        cout << R"(
�������� ������� �������:

    * * *       *           * * *                   * * *
� -   * *   � - * *     � -   *     � -   *     � -   *
        *       * * *                   * * *       * * *

    *   *       *               *       * * *           *
� - * * *   � - * *     � -   * *   � - * *     � -   * *
    *   *       *               *       *           * * *

0 - �����
)";
        cin >> Dark_Side;
        if (Dark_Side == '0')break; //����� �� ����� while(������ ���������)
        //������ � �������� � ����������� �� ���������
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                switch (Dark_Side)
                {
                case '�':
                case '�':
                    //������� �������� �
                    if (i <= j)
                    {
                        //���������� ������� ������� � ������������
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //���������� ������� ������� � �����������
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //����������� �����
                        Summa += Matrix[i][j];
                        //����������� ���-�� ��������� ���������
                        Count++;
                        //����� �� ����� ������� ��������
                        if (Matrix[i][j] > 0)cout << " ";//��������� ������ ����� ������������� ������
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                case '�':
                case '�':
                    //������� �������� �
                    if (i >= j)
                    {
                        //���������� ������� ������� � ������������
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //���������� ������� ������� � �����������
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //����������� �����
                        Summa += Matrix[i][j];
                        //����������� ���-�� ��������� ���������
                        Count++;
                        //����� �� ����� ������� ��������
                        if (Matrix[i][j] > 0)cout << " ";//��������� ������ ����� ������������� ������
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                case '�':
                case '�':
                    //������� �������� �
                    if (i <= j && i + j <= N - 1)
                    {
                        //���������� ������� ������� � ������������
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //���������� ������� ������� � �����������
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //����������� �����
                        Summa += Matrix[i][j];
                        //����������� ���-�� ��������� ���������
                        Count++;
                        //����� �� ����� ������� ��������
                        if (Matrix[i][j] > 0)cout << " ";//��������� ������ ����� ������������� ������
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                case '�':
                case '�':
                    //������� �������� �
                    if (i >= j && i + j >= N - 1)
                    {
                        //���������� ������� ������� � ������������
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //���������� ������� ������� � �����������
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //����������� �����
                        Summa += Matrix[i][j];
                        //����������� ���-�� ��������� ���������
                        Count++;
                        //����� �� ����� ������� ��������
                        if (Matrix[i][j] > 0)cout << " ";//��������� ������ ����� ������������� ������
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                case '�':
                case '�':
                    //������� �������� �
                    if ((i <= j && i + j <= N - 1) || (i >= j && i + j >= N - 1))
                    {
                        //���������� ������� ������� � ������������
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //���������� ������� ������� � �����������
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //����������� �����
                        Summa += Matrix[i][j];
                        //����������� ���-�� ��������� ���������
                        Count++;
                        //����� �� ����� ������� ��������
                        if (Matrix[i][j] > 0)cout << " ";//��������� ������ ����� ������������� ������
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                case '�':
                case '�':
                    //������� �������� �
                    if ((i >= j && i + j <= N - 1) || (i <= j && i + j >= N - 1))
                    {
                        //���������� ������� ������� � ������������
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //���������� ������� ������� � �����������
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //����������� �����
                        Summa += Matrix[i][j];
                        //����������� ���-�� ��������� ���������
                        Count++;
                        //����� �� ����� ������� ��������
                        if (Matrix[i][j] > 0)cout << " ";//��������� ������ ����� ������������� ������
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                case '�':
                case '�':
                    //������� �������� �
                    if (i >= j && i + j <= N - 1)
                    {
                        //���������� ������� ������� � ������������
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //���������� ������� ������� � �����������
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //����������� �����
                        Summa += Matrix[i][j];
                        //����������� ���-�� ��������� ���������
                        Count++;
                        //����� �� ����� ������� ��������
                        if (Matrix[i][j] > 0)cout << " ";//��������� ������ ����� ������������� ������
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                case '�':
                case '�':
                    //������� �������� �
                    if (i <= j && i + j >= N - 1)
                    {
                        //���������� ������� ������� � ������������
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //���������� ������� ������� � �����������
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //����������� �����
                        Summa += Matrix[i][j];
                        //����������� ���-�� ��������� ���������
                        Count++;
                        //����� �� ����� ������� ��������
                        if (Matrix[i][j] > 0)cout << " ";//��������� ������ ����� ������������� ������
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                case '�':
                case '�':
                    //������� �������� �
                    if (i + j <= N - 1)
                    {
                        //���������� ������� ������� � ������������
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //���������� ������� ������� � �����������
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //����������� �����
                        Summa += Matrix[i][j];
                        //����������� ���-�� ��������� ���������
                        Count++;
                        //����� �� ����� ������� ��������
                        if (Matrix[i][j] > 0)cout << " ";//��������� ������ ����� ������������� ������
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                case '�':
                case '�':
                    //������� �������� �
                    if (i + j >= N - 1)
                    {
                        //���������� ������� ������� � ������������
                        if (Matrix[i][j] > Max)Max = Matrix[i][j];
                        //���������� ������� ������� � �����������
                        if (Matrix[i][j] < Min)Min = Matrix[i][j];
                        //����������� �����
                        Summa += Matrix[i][j];
                        //����������� ���-�� ��������� ���������
                        Count++;
                        //����� �� ����� ������� ��������
                        if (Matrix[i][j] > 0)cout << " ";//��������� ������ ����� ������������� ������
                        cout << Matrix[i][j] << " ";
                    }
                    else cout << "    ";
                    break;
                default:
                    cout << "����������� ������ �������! ��������� ��������� ����������!" << endl;
                    Dark_Side = 'N'; //'N' - ������������ �������
                    break; //����� �� switch
                }
                if (Dark_Side == 'N')break; //����� �� ����� �� �������� j(�����������)
            }
            if (Dark_Side == 'N')break; //����� �� ����� �� �������� i(��������)
            cout << endl;
        }
        if (Dark_Side != 'N') //���� ��� ������ ���������� �������
        {
            cout << "���������� ��������� �������� " << Dark_Side << " �����: " << Count << endl;
            cout << "������������ ������� �������� " << Dark_Side << " �����: " << Max << endl;
            cout << "����������� ������� �������� " << Dark_Side << " �����: " << Min << endl;
            cout << "����� ��������� �������� " << Dark_Side << " �����: " << Summa << endl;
            Average = (float)Summa / Count; //��������� ������� ��������
            cout << "������� �������������� �������� ����� ��������� �������� " << Dark_Side << " �����: " << Average << endl;
            //���������� ���������� � ��������� ���������
            Max = -100;
            Min = 100;
            Summa = 0;
            Count = 0;
            Average = 0.0F;
        }
        system("pause");
    }
    cout << "�� ����� ������!" << endl;
    Sleep(1500);
}
