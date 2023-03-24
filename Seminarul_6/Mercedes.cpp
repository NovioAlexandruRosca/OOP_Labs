#include "Mercedes.h"

Mercedes::Mercedes()
{
	Fuel_Capacity = 900;
	Fuel_Consumption = 5;
	Avg_Speed = 90;
	finished = -1;
	time_of_finish = 0;
	name = "Mercedes";
}

void Mercedes::Weather_changes(double wed)
{
	Avg_Speed *= wed;
	Fuel_Consumption *= 1 + (1 - wed);
}

void Mercedes::Show_Details()
{
	cout << name << endl << Fuel_Capacity << endl << Fuel_Consumption << endl << Avg_Speed << endl << finished << endl << time_of_finish << endl << endl;
}

void Mercedes::Enough_Fuel(double Distance)
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