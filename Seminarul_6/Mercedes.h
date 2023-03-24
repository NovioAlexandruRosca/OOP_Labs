#pragma once
#include "Car.h"

class Mercedes : public Car
{
public:
	Mercedes();
	void Weather_changes(double);
	void Show_Details();
	void Enough_Fuel(double Distance);
};
