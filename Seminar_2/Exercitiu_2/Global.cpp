#include "Global.h"
#include "Student.h"
#include <cstring>

int comp_mate(float x, float y)
{
	if (x == y)
		return 0;
	else if (x > y)
		return 1;
	return -1;
}

int comp_istorie(float x, float y)
{
	if (x == y)
		return 0;
	else if (x > y)
		return 1;
	return -1;
}

int comp_engleza(float x, float y)
{
	if (x == y)
		return 0;
	else if (x > y)
		return 1;
	return -1;
}

int comp_avg(float x, float y)
{
	if (x == y)
		return 0;
	else if (x > y)
		return 1;
	return -1;
}

int comp_nume(char x[30], char y[30])
{
	if (strcmp(x,y) == 0)
		return 0;
	else if (strcmp(x,y) > 0)
		return 1;
	return -1;
}