#include "Volvo.h"
Volvo::Volvo() : Car("Volvo", 45, 8, 130, 75, 30) {}

double Volvo::calculateTime(int circuitLength, Weather weather)
{
    double time;
    double averageSpeed;

    switch (weather)
    {
    case Weather::Rain:
        averageSpeed = avg_speed_rain;
        break;
    case Weather::Sunny:
        averageSpeed = avg_speed_sunny;
        break;
    case Weather::Snow:
        averageSpeed = avg_speed_snow;
        break;
    }

    time = circuitLength / averageSpeed;

    return time;
}

std::string Volvo::GetName()
{
    return name;
}

bool Volvo::Finish(double circuit_len)
{
    if (fuel_cap * fuel_cons > circuit_len) return 1;
    return 0;
}