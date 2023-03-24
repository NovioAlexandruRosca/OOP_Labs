#include "Circuit.h"

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Dacia());
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());
	
	c.Race(); 
	c.ShowFinalRanks(); 
	c.ShowWhoDidNotFinish(); 
}