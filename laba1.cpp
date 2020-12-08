#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

class Array {
private:
	int n;
	int** arr;

public:

	Array(int n)
	{
		this->n = n;
		arr = new int* [n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new int[n];
		}
	}

	void FillMat()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << "a[" << i << "][" << j << "]= ";
				cin >> arr[i][j];
			}
		}
		cout << endl;
	}

	void multiply(Array& a, Array& b)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = 0;
				for (int k = 0; k < n; k++)
				{
					arr[i][j] += a.arr[i][k] * b.arr[k][j];
				}
			}
		}
	}

	void addition(Array& a, Array& b)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = a.arr[i][j] + b.arr[i][j];
			}
		}
	}

	void coutMat()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << setw(4) << arr[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	~Array()
	{
		for (int i = 0; i < n; i++)
		{
			delete[] arr[i];
		}
		delete[]arr;
	}
};


int main()
{
	setlocale(LC_ALL, "");
	int size;
	cout << "Введите размер матриц: ";
	cin >> size;
	Array arr1(size);
	Array arr2(size);
	arr1.FillMat();
	arr2.FillMat();

	Array arr3(size);
	Array arr4(size);
	arr3.multiply(arr1, arr2);
	cout << "Умножение матриц\n";
	arr3.coutMat();

	arr4.addition(arr1, arr2);
	cout << "Сложение матриц\n";
	arr4.coutMat();

}
