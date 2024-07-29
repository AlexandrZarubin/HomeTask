#include "Array.h"
//конструктор с параметром, принемает кол-во элементов
Array::Array(int Size) : size{ Size }, array{ new int[size] {} }
{
	if (!array) //проверка выделения памяти под поле array
	{
		cout << "Ошибка выделения памяти!" << endl;
		size = 0; //тогда создаем пустой массив
	}
	else cout << "Память для поля array объекта " << this << " успешно выделена в конструкторе с параметром!" << endl; //для теста
}
//конструктор копирования, lvalue ссылка(ссылка на именованный постоянный объект)
Array::Array(const Array& A) : size{ A.size }, array{ new int[size] {} }
{
	if (!array) //проверка выделения памяти под поле array
	{
		cout << "Ошибка выделения памяти!" << endl;
		size = 0; //тогда создаем пустой массив
	}
	else
	{
		cout << "Память для поля array объекта " << this << " успешно выделена в конструкторе с копирования!" << endl; //для теста
		for (int i = 0; i < size; i++)
		{
			array[i] = A.array[i]; //копируем значения элементов
		}
	}
}
//если в классе перегружен оператор копирующего присваивания, то можно его использовать в конструкторе копирования
//Array::Array(const Array& A)
//{
//	*this = A; //использование перегруженного оператор копирующего присваивания
//}
//конструктор перемещения служит для извлечения содержимого из одного объекта класса Array в другой при его создании
Array::Array(Array&& TMP) : size{ TMP.size }, array{ TMP.array } //копируем адрес выделенной памяти в исходном(временном) объекте в новый объект
{
	//отбираем право владения памятью у исходного(временного) объекта и "обнуляем" его
	TMP.array = nullptr;
	TMP.size = 0;
	cout << "Сработал конструктор перемещения для объекта " << this << ". Объект " << &TMP << " был опустошен!" << endl; //для теста
}
//конструктор списочной инициализации A{1,2,3}
//явный вызов конструктора(делигирование) с параметром и передача в него размера списка элементов
Array::Array(const initializer_list<int>& list) : Array((int)list.size())
{
	int i = 0;
	//range-base цикл
	for (auto element : list)			//for (int element : list)
		//вместо auto компилятор подставит тип данных, выбранный на основании содержимого
	{
		array[i] = element; //на каждом шаге цикла в element будут копироваться значения элементов из списка list
		i++;
	}
	cout << "Конструктор со списочной инициализацией объекта " << this << endl; //для теста
}
//Деструктор
Array::~Array()
{
	if (array) //если явно не вызывался деструктор, объект не был опустошен, не был пустым изначально
	{
		delete[] array; //освобождение памтяи под поле array
		array = nullptr;
		size = 0;
		cout << "Память, выделенная пол поле array объекта " << this << " успешно освобождена!" << endl; //для теста
	}
	else cout << "Память, выделенная пол поле array объекта " << this << " уже была освобождена!" << endl; //для теста
}
//сеттеры:
//метод заполнения массива случайными числами от указанного числа и до указанного числа включительно
void Array::Randomize(int begin, int end)
{
	//если массив пустой, то можно запросить размер, выделить память и заполнить
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % (end + 1 - begin) + begin; //rand()%(B-A)+A;
	}
}
//метод изменения размера массива
void Array::ReSize(int NewSize)
{
	//I Вариант. Выделение памяти только под поле array
	if (size == NewSize)return; //если текущий и новый размеры равны
	int* temp = nullptr; //временный массив элементов типа данных int
	if (NewSize > 0)temp = new int[NewSize] {}; //выделяем память под элементы типа данных int новым размером
	if (size != 0) //если в текущем объекте есть элементы
	{
		for (int i = 0; i < NewSize; i++) //копируем элементы из поля array текущего объекта в новую память
		{
			if (i < size)temp[i] = array[i]; //если ещё есть элементы в текущем объекте
			else break; //иначе выход из цикла копирования элементов из текущего объекта в новую память
		}
		delete[] array; //освобождаем старую память старого поля array
	}
	size = NewSize; //изменяем размер текущего объекта
	array = temp; //помещаем в поле array текущего объекта адрес новой памяти

	//II Вариант. Создание временного объекта нужного вида и размера
	//if (size == NewSize)return; //если текущий и новый размеры равны
	//if (NewSize == 0) //если новый размер должен стать нулевым
	//{
	//	this->~Array(); //явно вызываем деструктор для текущего объекта для его "обнуления"
	//	return;
	//}
	//Array Temp(NewSize); //создаем временный объект класса Array нужного размера
	//if (size != 0) //если в текущем объекте есть элементы
	//{
	//	for (int i = 0; i < NewSize; i++) //копируем элементы из поля array текущего объекта во временный объект Temp
	//	{
	//		if (i < size)Temp[i] = array[i]; //если ещё есть элементы в текущем объекте			
	//		else break; //иначе выход из цикла копирования элементов из текущего объекта в новую память
	//	}
	//}
	//*this = move(Temp); //отбираем содержимое у временного объекта(переобразуя его к rvalue, с помощью move) и 
	//присваиваем текущему объекту с помощью оператора перемещающего присваивания
}
//геттеры:
//метод получения текущего размера массива(кол-ва элементов)
int Array::Size() const //геттер для поля size
{
	return size;
}
//перегрузка операторов как методов класса
//перегрузка оператора индексирования []
//как сеттер и геттер для переменных объектов класса Array(для массива переменных типа данных int)
int& Array::operator[](int index)
{
	//проверку выхода за границы массива
	while (index < 0 || index >= size)
	{
		cout << "Выход за границы массива! Введите иднекс: ";
		cin >> index;
		//exit(3);
		//return array[0];
	}
	return array[index]; //возвращаем элемент с указанным индексом
}
//перегрузка оператора индексирования []
//как геттер для константных объектов класса Array(для массива констант типа данных int)
int Array::operator[](int index) const
{
	bool Error = (index >= 0 && index < size); //условие корректного индекса
	assert(Error && "Выход за границы массива!"); //сработает когда условие внутри () ложь (false)
	return array[index]; //возвращаем элемент с указанным индексом
}
//перегрузка оператора копирующего присваивания =
Array& Array::operator=(const Array& A)
{
	if (this != &A) //если это не один и тот же объект
	{
		if (size != A.size) //если не равны размеры
		{
			delete[] array; //удаляем старый массив из текущего объекта
			array = nullptr; //обнуляем указатель
			size = A.size; //получаем новый размер
			if (size) //если новый размер отличен от нуля, выделяем новую память нужного размера
			{
				array = new int[size] {};
				if (!array) //проверка выделения памяти под поле array
				{
					cout << "Ошибка выделения памяти!" << endl;
					size = 0; //тогда создаем пустой массив					
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			array[i] = A.array[i]; //копируем элемнеты в текущий объект
		}
	}
	cout << "Оператор копирующего присваивания из объекта " << &A << " в объект " << this << endl; //для теста
	return *this; //возвращаем ссылку на объект для которого вызывался оператор
}
//перегрузка оператора перемещающего присваивания = служит для извлченения содержимого из одного объекта класса Array в другой, уже созданный ранее объект 
Array& Array::operator=(Array&& A)
{
	//A = move(A);
	if (this != &A) //если это не один и тот же объект
	{
		delete[] array; //удаляем старый массив из текущего объекта
		array = A.array; //копируем адрес памяти из присваемого объекта в текущий
		size = A.size; //получаем новый размерэ
		//"обнуляем" присваиваемый объект
		A.array = nullptr;
		A.size = 0;
	}
	cout << "Оператор перемещающего присваивания из объекта " << &A << " в объект " << this << endl; //для теста
	return *this; //возвращаем ссылку на объект для которого вызывался оператор
}
//перегрузка оператора проверки на равенство ==
bool Array::operator==(const Array& A) const
{
	if (this == &A)return true; //если объект сравнивают сам с собой
	if (size != A.size) //елси размеры не равны
		return false;
	for (int i = 0; i < size; i++) //сравниваем элементы попарно
	{
		if (array[i] != A.array[i]) //как только найдены несовпадающие элементы
			return false;
	}
	return true;
}
//перегрузка оператора проверки на неравенство !=
bool Array::operator!=(const Array& A) const
{
	return !(*this == A); //обратный результат перегруженного оператора проверки на равенство ==
	//текущего объекта this и сравниваемого с ним объекта А
}

//--Сортировка массива
void Array::SortShell(bool Key)
{
	int temp = 0; //буфер для перестановки элементов местами
	//step - расстояние между сравниваемыми элементами
	for (int step = size / 2; step > 0; step /= 2) //цикл шагов с уменьшающимся в два раза расстоянием между сравниваемыми элементами
	{
		for (int i = step; i < size; i++) //цикл прохода по элементам массива(вперед)
		{
			if (Key) //если выбрана сортировка от меньшего к большему(по возрастанию)
			{
				for (int j = i - step; j >= 0 && array[j + step] < array[j]; j -= step)//цикл сравнения j-х элементов отстоящих от i-го на расстояние step
				{
					//меняем элементы местами, если правый меньше левого на расстояние step
					temp = array[j];
					array[j] = array[j + step];
					array[j + step] = temp;
				}
			}
			else //иначе от большего к меньшему(по убыванию значений)
			{
				for (int j = i - step; j >= 0 && array[j + step] > array[j]; j -= step)//цикл сравнения j-х элементов отстоящих от i-го на расстояние step
				{
					//меняем элементы местами, если правый больше левого на расстояние step
					temp = array[j];
					array[j] = array[j + step];
					array[j + step] = temp;
				}
			}
		}
	}

}

//--Array-=int
Array& Array::operator-=(int A)
{

	for (int i = 0; i < size; i++)
	{
		array[i] -= A;
	}
	return *this;
}
//--Array-=int
Array& Array::operator/=(int A)
{
	for (int i = 0; i < size; i++)
	{
		array[i] /= A;
	}
	return *this;
}
//--Array*=int
Array& Array::operator*=(int A)
{
	for (int i = 0; i < size; i++)
	{
		array[i] *= A;
	}
	return *this;
}
//--Array+=int
Array& Array::operator+=(int A)
{
	for (int i = 0; i < size; i++)
	{
		array[i] += A;
	}
	return *this;
}

//--array=Array-int
Array Array::operator-(int A)
{
	Array Temp(size); //временный оъект 
	for (int i = 0; i < size; i++)
	{
		Temp[i] = array[i] - A;
	}
	return Temp; //возвращаем значение временного объекта
}
//--array=Array/int
Array Array::operator/(int A)
{
	Array Temp(size); //временный оъект 
	for (int i = 0; i < size; i++)
	{
		Temp[i] = array[i] / A;
	}
	return Temp; //возвращаем значение временного объекта;
}
//--array=Array/int
Array Array::operator*(int A)
{
	Array Temp(size); //временный оъект 
	for (int i = 0; i < size; i++)
	{
		Temp[i] = array[i] * A;
	}
	return Temp; //возвращаем значение временного объекта;
}
//--array=Array+int
Array Array::operator+(int A)
{
	Array Temp(size); //временный объект 
	for (int i = 0; i < size; i++)
	{
		Temp[i] = array[i] + A;
	}
	return Temp; //возвращаем значение временного объекта;
}
//дружественная перегрузка операторов
//оператор вывода
ostream& operator<<(ostream& Out, const Array& A)
{
	//для дружественной перегрузки					//для глобальной перегрузки
	for (int i = 0; i < A.size; i++)				//for(int i = 0; i < A.Size(); i++)
	{
		Out << A.array[i] << " ";					//Out << A[i] << " ";
	}
	//Out << endl;
	return Out;
}
//оператор ввода
istream& operator>>(istream& In, Array& A)
{
	//для дружественной перегрузки					//для глобальной перегрузки
	for (int i = 0; i < A.size; i++)				//for(int i = 0; i < A.Size(); i++)
	{
		cout << "Введите " << i << "-ой элемент: ";
		In >> A.array[i];							//In >> A[i];
	}
	return In;
}
//--array=int-array
Array operator-(int A, const Array& B)
{
	Array Temp(B.size);
	for (int i = 0; i < B.size; i++)
	{
		Temp[i] = B.array[i] - A;
	}
	return Temp; //возвращаем значение временного объекта;
}
//--array=int+array
Array operator+(int A, const Array& B)
{
	Array Temp(B.size);
	for (int i = 0; i < B.size; i++)
	{
		Temp[i] = B.array[i] + A;
	}
	return Temp; //возвращаем значение временного объекта;
}
//--array=int*array
Array operator*(int A, const Array& B)
{
	Array Temp(B.size);
	for (int i = 0; i < B.size; i++)
	{
		Temp[i] = B.array[i] * A;
	}
	return Temp; //возвращаем значение временного объекта;
}
//--array=int/array
Array operator/(int A, const Array& B)
{
	Array Temp(B.size);
	for (int i = 0; i < B.size; i++)
	{
		Temp[i] = B.array[i] / A;
	}
	return Temp; //возвращаем значение временного объекта;
}

//глобальная перегрузка оператора сложение + (сложение массивов поэлементно)
const Array operator+(const Array& A, const Array& B)
{
	//размер нового временного объекта
	int MaxSize = (B.Size() > A.Size()) ? B.Size() : A.Size();
	Array Temp(MaxSize); //временный оъект размера MaxSize
	for (int i = 0; i < MaxSize; i++) //for (int i = 0; i < Temp.Size(); i++)
	{
		if (MaxSize == A.Size()) //если размер объекта А больше размера объекта В
		{
			if (i < B.Size()) //Пока в массиве В есть элементы
				Temp[i] = A[i] + B[i]; //суммируеем значения элементов в новый объект
			else Temp[i] = A[i]; //когда в объекте B закончатся элементы, передаем только элементы из объекта А
		}
		else //если размер объекта B больше размера объекта A
		{
			if (i < A.Size()) //Пока в массиве A есть элементы
				Temp[i] = A[i] + B[i]; //суммируеем значения элементов в новый объект
			else Temp[i] = B[i]; //когда в объекте A закончатся элементы, передаем только элементы из объекта B
		}
	}
	return Temp; //возвращаем значение временного объекта	
}
