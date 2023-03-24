#include "Circuit.h"
#include "Weather.h"
#include "Dacia.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Mazda.h"
#include <iostream>

using namespace std;

Circuit::Circuit()
{
	this->Length = 0;
	this->Number_of_Cars = 0;
	this->Weather_coeficient = 1;
	Car* Cars = new Car[1];
}
Circuit::~Circuit()
{
	this->Length = 0;
	delete[] Cars;
}

void Circuit::SetWeather(int weather_coeficient)
{
	Weather_coeficient = (double) weather_coeficient / 100;
}

void Circuit::AddCar(Car* newcar)
{
	Car** Digital = new Car*[Number_of_Cars + 1];

	for (int i = 0; i < Number_of_Cars; i++)
		Digital[i] = Cars[i];

	this->Number_of_Cars++;
	delete[] Cars;

	Cars = Digital;

	Cars[Number_of_Cars - 1] = newcar;
	Cars[Number_of_Cars - 1]->Weather_changes(this->Weather_coeficient);
}

void Circuit::SetLength(int Length)
{
	this->Length = Length;
}

void Circuit::Race()
{
	for (int i = 0; i < Number_of_Cars; i++)
	{
		Cars[i]->Enough_Fuel(Length);
	}
}

void Circuit::ShowFinalRanks()
{
	int cars_not_finished = 0;
	for (int i = 0; i < Number_of_Cars; i++)
	{
		if (Cars[i]->finished == 0)
		{
			cars_not_finished++;
		}
	}

	for(int i = 0 ; i < Number_of_Cars - 1 ; i++)
		for (int j = i + 1; j < Number_of_Cars; j++)
			if (Cars[i]->time_of_finish > Cars[j]->time_of_finish)
			{
				Car* auxiliar = Cars[j];
				Cars[j] = Cars[i];
				Cars[i] = auxiliar;
			}
	int j = 1;
	cout << "The cars that have finished are: " << endl;
	for (int i = cars_not_finished; i < Number_of_Cars; i++)
	{
		cout << "On the " << j << " place is " << Cars[i]->name << " with a time of " << Cars[i]->time_of_finish << " hours" << endl;
		j++;
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	int j = 1;
	cout << endl << "The cars that haven't finished are: " << endl << endl;
	for (int i = 0; i < Number_of_Cars; i++)
	{
		if (Cars[i]->finished == 0)
		{
			cout << j << ".The " << Cars[i]->name << " hasn't finished the race due to not having enough fuel " << "(" << Length - Cars[i]->Fuel_Capacity / Cars[i]->Fuel_Consumption << ") more liters were neccesary" << endl;
			j++;
		}
	}
}
