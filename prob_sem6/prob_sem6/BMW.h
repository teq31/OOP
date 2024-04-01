#pragma once
#include "Car.h"

class BMW : public Car
{
public:
    BMW();
    double calculateTime(int circuitLength, Weather weather);
    std::string GetName();
    bool Finish(double circuit_len);
};

