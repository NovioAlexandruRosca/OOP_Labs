#include "Sort.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <stdarg.h>
#include <cstring>
#include <initializer_list>

using namespace std;

void Sort::Print()
{
	for (int i = 0; i < this->n; i++)
		cout << this->v[i] << " ";
	cout << endl;
}

int Sort::GetElementsCount()
{
	return this->n;
}

int Sort::GetElementFromIndex(int i)
{
	return this->v[i];

}

void Sort::BubbleSort(bool ascendent)
{
	int OK = 1;

	while (OK)
	{
		OK = 0;
		for(int i = 0 ; i < this->n - 1 ; i++)
		if (ascendent ? this->v[i] > this->v[i + 1] : this->v[i] < this->v[i + 1]) {
			swap(this->v[i], this->v[i + 1]);
			OK = 1;
		}
	}
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 0; i < this->n ; i++)
	{
		int j = i;

		while (j > 0 && (ascendent ? this->v[j] < this->v[j - 1] : this->v[j] > this->v[j - 1]))
		{
			swap(this->v[j], this->v[j - 1]);
			j--;
		}
	}

}

void Sort::QuickSortHelper(int low, int high, bool ascendent)
{
	if (low < high)
	{
		int pivot = Sort::Partition(low, high, ascendent);
		Sort::QuickSortHelper(low, pivot - 1, ascendent);
		Sort::QuickSortHelper(pivot + 1, high, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	int n = Sort::GetElementsCount();
	QuickSortHelper(0, n - 1, ascendent);
}

int Sort::Partition(int low, int high, bool ascendent)
{
	int pivot = this->v[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (ascendent ? (this->v[j] <= pivot) : (this->v[j] >= pivot))
		{
			i++;
			swap(this->v[i], this->v[j]);
		}
	}
	swap(this->v[i + 1], this->v[high]);
	return i + 1;
}

Sort::Sort(int mini, int maxi, int m)
{
	srand(time(NULL));

	this->n = m;
	this->v = new int[this->n];

	for (int i = 0; i < m ; i++)
		this->v[i] = rand() % (maxi - mini) + mini;

}

Sort::Sort(int* x, int m)
{
	this->n = m;
	this->v = new int[this->n];

	for (int i = 0; i < m; i++)
		this->v[i] = x[i];

}

Sort::Sort(int count, ...)
{
	this->n = count;
	this->v = new int[count];

	va_list list;
	va_start(list, count);

	for (int i = 0; i < count; i++)
	{
		this->v[i] = va_arg(list, int);
	}
	va_end(list);
}

Sort::Sort(initializer_list<int> init_list)
{
	this->v = new int[init_list.size()];
	this->n = init_list.size();
	copy(init_list.begin(), init_list.end(), this->v);

}

Sort::Sort(char* sir) {

	int n = 0;
	char* p = strtok(sir, ",");
	this->v = new int[1];

	while (p) {

		int* digital = new int[n + 1];

		for (int i = 0; i < n; i++) 
			digital[i] = this->v[i];


		digital[n] = atoi(p);

		n++;

		delete[] this->v;
		
		this->v = digital;
		
		p = strtok(NULL, ",");
	}
	this->n = n;

}


Sort::~Sort()
{
	delete[] this->v;
	this->n = 0;
}