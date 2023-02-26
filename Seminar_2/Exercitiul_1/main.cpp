#include <stdlib.h>
#include <stdio.h>
#include "NumberList.h"

int main()
{
	NumberList Set;
	int n,array_full = 0;

	Set.Init();

	printf("Give an N : ");
	scanf("%d", &n);

	for (int i = 0; i < n && !array_full; i++)
	{
		int x;
		printf("%d.Give an X : ",i + 1);
		scanf("%d", &x);
		if (Set.Add(x) == 0)
		{
			printf("\nError nb.1,can't add more itemes in the array!\n");
			array_full = 1;
		}
	}

	printf("\n1 . Unsorted array : ");
	Set.Print();

	printf("\n2 . Sorted array : ");
	Set.Sort();
	Set.Print();
	printf("\n");
}
