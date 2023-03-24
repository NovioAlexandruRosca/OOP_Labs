#include "Mazda.h"

Mazda::Mazda()
{
	Fuel_Capacity = 150;
	Fuel_Consumption = 3;
	Avg_Speed = 5;
	finished = -1;
	time_of_finish = 0;
	name = "Mazda";
}

void Mazda::Weather_changes(double wed)
{
	Avg_Speed *= wed;
	Fuel_Consumption *= 1 + (1 - wed);
}

void Mazda::Show_Details()
{
	cout << name << endl << Fuel_Capacity << endl << Fuel_Consumption << endl << Avg_Speed << endl << finished << endl << time_of_finish << endl << endl;
}

void Mazda::Enough_Fuel(double Distance)
{
	if (Fuel_Capacity / Fuel_Consumption < Distance)
		finished = 0;
	else
		finished = 1;

	if (finished == 1)
	{
		time_of_finish = Distance / Avg_Speed;
	}
}