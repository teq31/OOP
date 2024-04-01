#pragma once
#include "Car.h"

class RangeRover : public Car
{
public:
    RangeRover();
    double calculateTime(int circuitLength, Weather weather);
    std::string GetName();
    bool Finish(double circuit_len);
};

