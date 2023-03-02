#include <iostream>
#include "Canvas.h"

using namespace std;

int main()
{
	Canvas Poza(100,100);

	Poza.FillCircle(95, 95, 10, 'a');
	Poza.Print();

}