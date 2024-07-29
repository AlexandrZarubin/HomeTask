#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
using namespace std;

class Image
{
	//const int Lenght=5;
	//const int Weidth = 5;
	int Lenght;
	int Weidth;
	class Pixel
	{
		int Red;
		int Green;
		int Blue;
	public:
		Pixel(int r, int g, int b)
		{
			Red = r;
			Green = g;
			Blue = b;
		}
		void SetPix(int r, int g, int b)
		{
			Red = r;
			Green = g;
			Blue = b;
		}
		Pixel() = default;
		~Pixel() {/*cout << "yd2"*/ };
		string GetPix()//но поля остаются в int
		{
			return " Red " + to_string(Red) + " Green " + to_string(Green) + " Blue " + to_string(Blue);
		}
	};
	Pixel** Picture;

public:
	//Image() = default;
	~Image()
	{
		for (int i = 0; i < Weidth; i++)
		{
			delete[] Picture[i];
			Picture[i] = nullptr;
			//cout << "уд" << endl;
		}
	}
	Image(int W, int L) :Weidth{ W }, Lenght{ L }
	{
		Picture = new Pixel * [Weidth] {};
		for (int i = 0; i < Weidth; i++)
		{
			Picture[i] = new Pixel[Lenght];
		}
	}
	void PixelRand(int begin, int end)
	{
		for (int i = 0; i < Weidth; i++)
		{
			for (int j = 0; j < Lenght; j++)
			{
				int Red = rand() % (end + 1 - begin) + begin;
				int Green = rand() % (end + 1 - begin) + begin;
				int Blue = rand() % (end + 1 - begin) + begin;
				Picture[i][j].SetPix(Red, Green, Blue);
			}
		}
	}
	void GetShow()const
	{
		for (int i = 0; i < Weidth; i++)
		{
			for (int j = 0; j < Lenght; j++)
			{
				cout << i + 1 << "." << j + 1 << ". " << Picture[i][j].GetPix() << endl;
			}
			cout << endl;
		}
	}

	template <typename T>friend T Save(string, T&, T&);
	template <typename T>friend void Load(string, T&, T&);
};
template <typename T> T Save(string pach, T& obj, T& clss)
{
	fstream Out;
	Out.open("pach");
	if (!Out.is_open())
	{
		cout << "error" << endl;
	}
	else
	{
		cout << "fail open" << endl;
		Out.write((char*)&obj, sizeof(clss));
	}
	Out.close();
	return;
}
template <typename T> void Load(string pach, T& obj, T& clss)
{
	ifstream In;
	In.open("pach", ios::binary);
	while (In.read((char*)&obj, sizeof(clss)))
		//while (!In.eof())
	{
		clss.GetShow();
	}
	In.close();
	return;
}
int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Image img(5, 5);
	img.GetShow();
	system("pause");
	img.PixelRand(0, 9);
	img.GetShow();

	cout << endl << endl;

	/*string Path ;    !!!!!
	Path += "Image.txt";
	Save(Path, img, Image);*/

	ofstream Out;
	Out.open("Image.txt", ios::binary);
	if (!Out.is_open())
	{
		cout << "error" << endl;
	}
	else
	{
		cout << "fail open" << endl;
		Out.write((char*)&img, sizeof(Image));
	}
	Out.close();

	Image Buffer(5, 5);

	ifstream In;
	In.open("Image.txt", ios::binary);
	while (In.read((char*)&Buffer, sizeof(Image)))
		//while (!In.eof())
	{
		Buffer.GetShow();
	}
	In.close();



}