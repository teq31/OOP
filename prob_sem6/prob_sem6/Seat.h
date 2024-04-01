#pragma once
#include "Car.h"

class Seat : public Car
{
public:
    Seat();
    double calculateTime(int circuitLength, Weather weather);
    std::string GetName();
    bool Finish(double circuit_len);
};

