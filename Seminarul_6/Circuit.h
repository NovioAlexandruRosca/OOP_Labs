#pragma once
#include "Weather.h"
#include "Dacia.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Mazda.h"

class Circuit
{
	private:
		double Length;
		int Number_of_Cars;
		double Weather_coeficient;
		Car** Cars;

	public:
		Circuit();
		~Circuit();
		void AddCar(Car*);
		void SetWeather(int);         // Done
		void SetLength(int Length);   // Done
		void Race();                  // Done
		void ShowFinalRanks();        // Done
		void ShowWhoDidNotFinish();   // Done

};