#pragma once
#include "Car.h"
#include <vector>

class Circuit 
{
public:
    void SetLength(int length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
private:
    double circuitLength;
    Weather weather;
    std::vector<Car*> cars;
};