#include "Sort.h"
#include <iostream>
using namespace std;

int main()
{

	//Sort Object(40,50,10);
	//int v[4] = { 1,3,2,0 };
	//Sort Object(v, 4);
	//Sort Object(5, 5, 4, 3, 2, 10);
	Sort Object({ 2,1,3 });
	Sort Ob = Object;

	//char x[] = "100,20,30";
	//Sort Object(x);

	Object.Print();
	Object.QuickSort(true);
	Object.Print();
	Object.QuickSort(false);
	Object.Print();


	cout << endl;
	Ob.Print();
	Ob.InsertSort(false);
	Ob.Print();


	Sort Object_move = move(Object);

	cout << endl;
	Object_move.Print();
	Object_move.BubbleSort(true);
	Object_move.Print();

}