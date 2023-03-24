#pragma once
#include "Car.h"
#include <iostream>


class Dacia : public Car
{
public:
	Dacia();
	void Weather_changes(double);
	void Show_Details();
	void Enough_Fuel(double Distance);
};