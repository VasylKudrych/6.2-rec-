// 6.2 - rec
// варіант 24*

#include <iostream>
#include <iomanip>

using namespace std;
void Print(int* a, const int size, int i);
void Sort(int* a, const int size, int i, int j, int& k);
void Create(int* a, const int size, const int High, int i);

int main()
{
	srand((unsigned)time(0));
	int k = 0; 
	const int n = 20; 
	int a[n];
	Create(a, n, 100, 0); 
	cout << "start array = ";
	Print(a, n, 0); 
	Sort(a, n, 1, 0, k); 
	cout << "sorted array = ";
	Print(a, n, 0); 
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

void Sort(int* a, const int size, int i, int j, int& k) 
{
	if (a[j] < a[j + 1]) 
	{ 
		int tmp = a[j + 1];
		a[j + 1] = a[j];
		a[j] = tmp;
		k = 1;
	}
	if (j < size - i - 1) 
		Sort(a, size, i, j + 1, k); 
	if (k == 0) 
		return; 
	if (i < size - 1) 
	{
		k = 0; 
		Sort(a, size, i + 1, 0, k); 
	}
}

void Create(int* a, const int size, const int High, int i)
{
	if (i < size)
	{
		a[i] = rand() % High;
		Create(a, size, 100, i + 1);
	}
}
