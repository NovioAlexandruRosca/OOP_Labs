#pragma once
#include "Car.h"


class Toyota : public Car
{
public:
	Toyota();
	void Weather_changes(double);
	void Show_Details();
	void Enough_Fuel(double Distance);
};
