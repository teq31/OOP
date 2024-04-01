#include "Circuit.h"
#include <iostream>

void Circuit::SetLength(int length) 
{
    circuitLength = length;
}

void Circuit::SetWeather(Weather w)
{
    weather = w;
}

void Circuit::AddCar(Car* car) 
{
    cars.push_back(car);
}

void Circuit::Race() 
{
    bool ok = 0;
    while (!ok)
    {
        ok = 1;
        for (int i = 0; i < cars.size() - 1; i++)
            if (cars[i]->calculateTime(circuitLength, weather) < cars[i + 1]->calculateTime(circuitLength, weather))
            {
                std::swap(cars[i], cars[i + 1]);
                ok = 0;
            }
    }
}

void Circuit::ShowFinalRanks()
{
    std::cout << "Finished" << std::endl;
    for (int i = 0; i < cars.size(); i++)
    {
        std::string name;
        name = cars[i]->GetName();
        if (cars[i]->Finish(circuitLength)) std::cout << name << std::endl;
    }
}

void Circuit::ShowWhoDidNotFinish()
{
    std::cout << "Not finished" << std::endl;
    for (int i = 0; i < cars.size(); i++)
    {
        Car* car = cars[i];
        std::string name;
        name = car->GetName();
        if ( !car->Finish(circuitLength)) std::cout << name << std::endl;
    }
}
