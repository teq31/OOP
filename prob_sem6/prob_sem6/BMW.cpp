#include "BMW.h"
BMW::BMW() : Car("BMW", 70, 9, 150, 80, 95) {}

double BMW::calculateTime(int circuitLength, Weather weather)
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

std::string BMW::GetName()
{
    return name;
}

bool BMW::Finish(double circuit_len)
{
    if (fuel_cap * fuel_cons > circuit_len) return 1;
    return 0;
}