#pragma once
#include "Car.h"

class Volvo : public Car
{
public:
    Volvo();
    double calculateTime(int circuitLength, Weather weather);
    std::string GetName();
    bool Finish(double circuit_len);
};

