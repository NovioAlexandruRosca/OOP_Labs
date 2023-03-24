#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Car
{
	public:
		double Fuel_Capacity = -1;     // Numar de litri de combustibil
		double Fuel_Consumption = -1;  // Consum pe km parcurs
		double Avg_Speed = -1;         // km/h
		int finished = -1;
		double time_of_finish = 0;
		string name;

		virtual void Weather_changes(double wed) {}
		virtual void Show_Details() {}
		virtual void Enough_Fuel(double Distance) {}
		
};