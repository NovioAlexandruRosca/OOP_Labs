#include "Math.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
	printf("1.Add(int,int) = %d\n", Math::Add(1, 2));
	printf("2.Add(int,int,int) = %d\n", Math::Add(1, 2,3));
	printf("3.Add(double,double) = %d\n", Math::Add(1.0, 2.2));
	printf("4.Add(double,double,double) = %d\n", Math::Add(1.0, 2.0,3.3));
	printf("5.Mul(int,int) = %d\n", Math::Mul(1, 3));
	printf("6.Mul(int,int,int) = %d\n", Math::Mul(1, 2, 5));
	printf("7.Mul(double,double) = %d\n", Math::Mul(1.0, 2.7));
	printf("8.Mul(double,double,double) = %d\n", Math::Mul(1.0, 2.0, 3.7));
	printf("9.Add(int(count),...) = %d\n", Math::Add(4,1,2,1,1));
	
	char* delete_this;
	delete_this = Math::Add(nullptr, nullptr);
	printf("10.Add(const char,const char) = %s\n",delete_this );
	delete[] delete_this;
}