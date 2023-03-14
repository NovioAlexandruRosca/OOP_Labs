#include <initializer_list>
#include <algorithm>
#include <iostream>

class Sort
{

	int* v;
	int n;
	void QuickSortHelper(int, int, bool);
	int Partition(int, int, bool);

public:
	
	Sort(int min, int max, int n);
	Sort(int*, int);
	Sort(int count, ...);
	Sort(std::initializer_list<int> init_list);
	Sort(char*);
	
	Sort(const Sort& d)
	{
		n = d.n;
		v = new int[this->n];

		for (int i = 0; i < this->n ; i++)
			v[i] = d.v[i];
	}

	Sort(Sort && d)
	{
		std::swap(n, d.n);
		std::swap(v, d.v);

	}

	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int GetElementsCount();
	int GetElementFromIndex(int index);

	~Sort();
};
