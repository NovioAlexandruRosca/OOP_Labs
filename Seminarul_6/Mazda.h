#pragma once
#include "Car.h"

class Mazda : public Car
{
public:
	Mazda();
	void Weather_changes(double);
	void Show_Details();
	void Enough_Fuel(double Distance);
};