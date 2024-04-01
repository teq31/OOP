#pragma once
#include "Weather.h"
#include <string>
class Car 
{
protected:
    std::string name;
    double fuel_cap;
    double fuel_cons;
    double avg_speed_sunny;
    double avg_speed_rain;
    double avg_speed_snow;

public:
   Car(std::string name, double fuel_cap, double fuel_cons, double avg_speed_sunny, double avg_speed_rain, double avg_speed_snow);
   virtual double calculateTime(int circuitLength, Weather weather) = 0;
   virtual std::string GetName() = 0;
   virtual bool Finish(double circuit_len) = 0;
};
