#include "Car.h"

Car::Car(std::string name, double fuel_cap, double fuel_cons, double avg_speed_sunny, double avg_speed_rain, double avg_speed_snow) :
	name(name), fuel_cap(fuel_cap), fuel_cons(fuel_cons), avg_speed_sunny(avg_speed_sunny), avg_speed_rain(avg_speed_rain), avg_speed_snow(avg_speed_snow)
{}