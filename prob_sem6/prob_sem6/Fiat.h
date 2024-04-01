#pragma once
#include "Car.h"

class Fiat : public Car
{
public:
    Fiat();
    double calculateTime(int circuitLength, Weather weather);
    std::string GetName();
    bool Finish(double circuit_len);
};

