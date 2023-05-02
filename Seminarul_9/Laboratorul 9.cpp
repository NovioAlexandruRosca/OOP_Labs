#include "Map.h"

int main() 
{ 
	Map<int,const char*> m;

	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";

	printf("Numarul de chei este:%d\n", m.Count());
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	} 
	
	printf("\n");

	m[20] = "result";
	
	// Clear
	//m.Clear();

	// Set
	m.Set(40, "test");
	
	// Delete
	m.Delete(40);

	// Count
	printf("Numarul de chei este:%d\n", m.Count());
	for (auto [key, value, index] : m) 
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	// Get

	int v1 = 20;
	const char* nume;

	if (m.Get(v1, nume))
		printf("\nValoarea este %s\n\n", nume);
	else
		printf("\nNu exista\n\n");


	// Includes

	Map<int, const char*> m1;

	m1[100] = "?";

	if (m.Includes(m1))
		printf("Da este inclusa\n");
	else
		printf("Nu este inclusa\n");
}