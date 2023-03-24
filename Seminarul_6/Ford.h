#pragma once
#include "Car.h"

class Ford : public Car
{
public:
	Ford();
	void Weather_changes(double);
	void Show_Details();
	void Enough_Fuel(double Distance);
};